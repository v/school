import sys, os
import re


if (len(sys.argv) < 4):
	print "Not enough arguments"
	print "Usage: parse_iloc.py <iloc_file> <allocation_scheme> <number of total registers>"
	sys.exit();

# Returns a hash that returns information about which virtual register is allocated to which physical register.

def naive_register_allocate(code, available):
	register_freqs = {}

	for line in code:
		for register in line['read']:
			if(not register.startswith('r')): 
				continue
			if(register in register_freqs):
				register_freqs[register] += 1
			else:
				register_freqs[register] = 1
		if(line['write'] and line['write'].startswith('r')):
			register = line['write']
			if(register in register_freqs): 
				register_freqs[register] += 1
			else:
				register_freqs[register] = 1
	items = sorted(register_freqs.items(), key=lambda x: -1*x[1])

#	print items
	
	rv = {} 
	for i in range(0, available):
		if i >= len(items):
			break
		rv[items[i][0]] = 'r'+str(i+1)
	
#	print rv
	return rv

def is_used_in_future(reg, code, line):
	for i in range(line, len(code)):
		if reg in code[i]['read'] or reg == code[i]['write']:
			return True
	return False

def my_max(iterable, key=lambda x: x):
	if not len(iterable):
		return None

	rv = iterable[0]
	for i in range(1, len(iterable)):
		if key(rv) < key(iterable[i]):
			rv = iterable[i]

	return rv

def get_free_reg(assigned_registers, reg_list, reg):
	for physical_reg, assigned_reg in assigned_registers.items():
		if assigned_reg not in reg_list:
			assigned_registers[physical_reg] = reg
			return physical_reg

	print "ALLOCATION ERROR. PLEASE FIX"
	sys.exit()


# Analyzes the live range conflicts in the code, and returns back register assignments.
def analyze_conflicts(conflicts, available):

	register_start = {}
	register_end = {}
	prev_regs = set()
	for i, regs in conflicts.items():
		for reg in regs:
			if not register_start.has_key(reg):
				register_start[reg] = i
			register_end[reg] = i

	range_length = {}

	for reg, start_index in register_start.items():
		range_length[reg] = register_end[reg] - start_index



	lives = map(lambda x: len(x), conflicts.values())
	if lives:
		max_live = max(lives)
	else:
		max_live = available

	while max_live > available:
		#We spill the register with the longest live range
		to_spill = my_max(range_length.items(), lambda x: x[1])

		del range_length[to_spill[0]]

		for i, reg_list in conflicts.items():
			#This register is no longer in conflict
			conflicts[i].discard(to_spill[0])

		lives = map(lambda x: len(x), conflicts.values())
		max_live = max(lives)


	reg_assns = {}
	reg_num = 0

	assigned_registers = {}
	for i in range(0, available):
		if i > len(conflicts):
			break
		assigned_registers['r'+str(i+1)] = ''


	for i, reg_list in conflicts.items():
		for reg in reg_list:

			if not reg_assns.has_key(reg):
				reg_assns[reg] = get_free_reg(assigned_registers, reg_list, reg)

	return reg_assns
	


def live_range_top_down_allocate(code, available):
	live_ranges = []

	prev_reg_list = set()

	for i in range(0, len(code)):
		line = code[i]

		# add read registers
		read_regs = filter(lambda x: x[0] == 'r', line['read'])

		prev_reg_list = prev_reg_list.union(read_regs)

		live_ranges.append(set())
		for reg in prev_reg_list:
			if is_used_in_future(reg, code, i):
				live_ranges[i].add(reg)
			else:
				live_ranges[i-1].add(reg)

		if line['write'] and line['write'][0] == 'r' :
			if is_used_in_future(line['write'], code, i):
				live_ranges[i].add(line['write'])
				prev_reg_list.add(line['write'])
		to_remove = []
		for elem in prev_reg_list:
			if not is_used_in_future(elem, code, i):
				to_remove.append(elem)

		prev_reg_list -= set(to_remove)

	conflicts = {}

	for i in range(0, len(live_ranges)):
		conflicts[i] = live_ranges[i]
#		print print_lineobj(code[i]), " Live Ranges: ", live_ranges[i]
	
	return analyze_conflicts(conflicts, available)

# Replaces registers on one line object according to reg_assns.
def replace_register(reg, reg_assns):
	if(not reg.startswith('r')):
		return reg

	if(reg_assns.has_key(reg)):
		return reg_assns[reg]
	else:
		return None

def print_lineobj(lineobj):	
	return lineobj['instruction']+ "\t"+ implode(lineobj['read'])+ " => "+ lineobj['write']

#Implementation of php's implode
def implode(arr, glue=", "):
	rv = ""
	for item in arr:
		rv += item + glue

	return rv[:-1*len(glue)]

NUM_TOTAL_REGISTERS = int(sys.argv[3])
NUM_FEASIBLE_REGISTERS = 2

FEASIBLE_1 = 'r' + str(NUM_TOTAL_REGISTERS-NUM_FEASIBLE_REGISTERS+1)
FEASIBLE_2 = 'r' + str(NUM_TOTAL_REGISTERS-NUM_FEASIBLE_REGISTERS+2)

#Returns back the key FEASIBLE_1/FEASIBLE_2 that represents a free register, and a boolean true/false that specifies whether a spill should occur or not. Returns None if no free registers are found.
def get_free_register(feasible_table, alloc_register=''):
	if not feasible_table[FEASIBLE_1]['value']:
		return FEASIBLE_1, True

	if not feasible_table[FEASIBLE_2]['value']:
		return FEASIBLE_2, True

	if feasible_table[FEASIBLE_1]['value'] == alloc_register :
		return FEASIBLE_1, False

	if feasible_table[FEASIBLE_2]['value'] == alloc_register :
		return FEASIBLE_2, False

	if feasible_table[FEASIBLE_1]['dirty']:
		return FEASIBLE_1, True

	if feasible_table[FEASIBLE_2]['dirty']:
		return FEASIBLE_2, True

	return None, True

symbol_table = {}

def get_address(reg):
	if(symbol_table.has_key(reg)):
		return str(symbol_table[reg])
	all_addresses = map(lambda x: x[1], symbol_table.items())

	if not all_addresses:
		lowest_addr = 1024
	else: 
		lowest_addr = min(all_addresses)

	if lowest_addr < 0:
		print "RAN OUT OF SPILL SPACE!"
		sys.exit();

	symbol_table[reg] = (lowest_addr-4)
	return str(lowest_addr - 4);

def spilled_before(reg):
	if(symbol_table.has_key(reg)):
		return str(symbol_table[reg])
	return None




			

def shape(code, reg_assns):
	rv = ""
# Structure:
# feasible_table = [{FEASIBLE_1 => {'value' => 'r13', 'dirty' => 0}}]
	feasible_table = {FEASIBLE_1: {'value': '', 'dirty': 0}, FEASIBLE_2 : {'value' : '', 'dirty' : 0}}
	for lineobj in code:
		line = ""

		readregs = []

		for reg in lineobj['read']:
			newreg = replace_register(reg, reg_assns)
#			print 'line obj', lineobj, ' newreg ', newreg
			if(not newreg):
				#add load code.
				free_reg, spill = get_free_register(feasible_table, reg)
				if not free_reg:
					print "Error allocating ", reg, " on line ", lineobj, " feasible table = ", feasible_table, "\n"
					sys.exit()

				feasible_table[free_reg]['value'] = reg
				feasible_table[free_reg]['dirty'] = 0
				 
				if spill:
					line += "// Loading "+reg+" from memory into "+free_reg+".\n"

					line += 'loadI '+get_address(reg)+' => '+free_reg+"\t//@"+reg+"\n" 
					line += 'load '+free_reg+' => '+free_reg+"\n"

					line += "\n"

				else:
					line += '// Cache Hit: Loading '+reg+' from register '+free_reg+"\n"

				readregs.append(free_reg)
			else:
				readregs.append(newreg)


		line += lineobj['instruction']
		
		line += "\t"
		
		if(lineobj['instruction'] == 'store'):
			line += implode(readregs, ' => ' ) + "\n"

		else:
			
			line += implode(readregs)

			if readregs:
				line +=	" => " 


			writereg = replace_register(lineobj['write'], reg_assns)

			if not writereg:

				#add store code
				free_reg, spill = get_free_register(feasible_table, lineobj['write'])
				if not free_reg:
					free_reg = FEASIBLE_2

				feasible_table[free_reg]['value'] = lineobj['write']
				feasible_table[free_reg]['dirty'] = 0
				
				line += free_reg + "\n"

				if free_reg == FEASIBLE_1:
					other_reg = FEASIBLE_2  
				else:
					other_reg = FEASIBLE_1


				# add store code
				line += "//Storing "+ lineobj['write']+ " into memory. \n"
				line += " loadI "+get_address(lineobj['write'])+" => "+other_reg+"\t //@"+lineobj['write']+"\n"

				feasible_table[other_reg]['value'] = '@'+lineobj['write']
				feasible_table[other_reg]['dirty'] = 0

				line += " store "+free_reg+" => "+other_reg+"\n"

				writereg = lineobj['write']

			else:
				line += writereg + "\n"


		feasible_table[FEASIBLE_1]['dirty'] = 1
		feasible_table[FEASIBLE_2]['dirty'] = 1

		rv += line

	return rv

def flip_dict(d):
	return dict([(v, k) for (k, v) in d.iteritems()])

def calc_distance(code, index, reg):
	for i in range(index, len(code)):
		line = code[i]
		if(reg in line['read'] or reg == line['write']):
			return i - index
		
	return 100000000

#Figures out the next register that you should use for allocation purposes. Also returns as a second return value, the register that was spilled to make this allocation.
def bu_get_next_reg(code, index, symbol_table, reg, available):
	if symbol_table.has_key(reg):
		return symbol_table[reg], None

	if(len(symbol_table) < available):
		symbol_table[reg] = 'r' + str(len(symbol_table)+1)
		return symbol_table[reg], None

	distance = {}
	# how far away are all these virtual registers from use?
	for virtual_r, physical_r in symbol_table.iteritems():
		distance[virtual_r] = calc_distance(code, index, virtual_r)

	to_spill = my_max(distance.items(), key=lambda x: x[1])

	newreg = symbol_table[to_spill[0]]
	del symbol_table[to_spill[0]]


	symbol_table[reg] = newreg

	if(distance == 100000000):
		return newreg, None

	return newreg, to_spill[0]

		


def bottom_up_allocate(code, available):
	register_assignments = []
	symbol_table = {}

	feasible_table = {FEASIBLE_1: {'value': '', 'dirty': 0}, FEASIBLE_2 : {'value' : '', 'dirty' : 0}}

	rv = ""

	for i in range(0, len(code)):
		gen_line = ""
		line = code[i]

		line_assignments = {}

		readregs = []

		# assign registers for read.
		for reg in line['read']:
			if reg.startswith('r'):
				# assigns a register to it. Spills if necessary.
				line_assignments[reg], spilled = bu_get_next_reg(code, i, symbol_table, reg, available)

				readregs.append(line_assignments[reg])
			
				if spilled: 
					# generate spill code for spilled.
					gen_line += "//  bbb Storing "+ spilled+ " into memory. \n"
					gen_line += " loadI "+get_address(spilled)+" => "+FEASIBLE_1+" //@ "+spilled+" \n"
					gen_line += " store "+line_assignments[reg]+" => "+FEASIBLE_1+" \n"
			else:
				readregs.append(reg)

		#need to load previously spilled read registers here.

		if i-1 > 0: 
			old_regs = set(map(lambda x: x[0], register_assignments[i-1].items()))
			new_regs = set(filter(lambda x: x[0].startswith('r'), symbol_table.items()))

			to_load = filter(lambda x: spilled_before(x), new_regs - old_regs)

			for reg in to_load:
				gen_line += "//Loading "+reg+" into "+line_assignments[reg]+" from memory location "+get_address(reg)+" \n"
				gen_line += "loadI "+get_address(reg)+"\t => "+FEASIBLE_1+" //@"+reg+" \n"
				gen_line += "load "+FEASIBLE_1+"\t => "+line_assignments[reg]+" \n"

		gen_line += line['instruction'] + "\t"

		if line['instruction'] == 'store':
			gen_line += implode(readregs, ' => ') + "\n"

		else:
			gen_line += implode(readregs)

			if readregs:
				gen_line += ' => '

			if(line['write'] and line['write'].startswith('r')):
				line_assignments[line['write']], spilled = bu_get_next_reg(code, i, symbol_table, line['write'], available)
				# generate spill code for spilled. Add it before the current line of code.
				if spilled: 
					#print "Spilled: ", spilled, " line['write'] ", line['write'], " line_assignments = ", line_assignments
					rv += "// aaa Storing "+ spilled+ " into memory. \n"
					rv += " loadI "+get_address(spilled)+" => "+FEASIBLE_1+" //@ "+spilled+" \n"
					rv += " store "+line_assignments[line['write']]+" => "+FEASIBLE_1+" \n"
				gen_line += line_assignments[line['write']] + "\n"
			else:
				gen_line += line['write'] + "\n"


		register_assignments.append(dict(symbol_table))
		rv += gen_line 
	
	return rv


code = []
filename = sys.argv[1]

#Build code data structure.
for line in open(filename):
	line = line.strip()
	if(line.startswith('//')):
		continue
	if not line:
		continue

	lineobj = {}
	sp = line.split()

	lineobj['instruction'] = sp[0]
	lineobj['write'] = sp[-1]
	lineobj['read'] = [] 

	if(sp[-2] == '=>'):
		for i in range(1, len(sp)-2):
			register = sp[i].strip(',')
#			if(register not in lineobj['read']):
			lineobj['read'].append(register)
	if(lineobj['instruction'] == 'store'):
		lineobj['read'].append(lineobj['write'])
		lineobj['write'] = ''
	
	code.append(lineobj)

#print code
if sys.argv[2] == '0':
	register_freqs = naive_register_allocate(code, NUM_TOTAL_REGISTERS-NUM_FEASIBLE_REGISTERS)
	print "//Naive Register Assignments: ", register_freqs

elif sys.argv[2] == '1':
	register_freqs = live_range_top_down_allocate(code, NUM_TOTAL_REGISTERS-NUM_FEASIBLE_REGISTERS)
	print "//Smart Register Assignments: ", register_freqs
elif sys.argv[2] == '2':
	print bottom_up_allocate(code, NUM_TOTAL_REGISTERS-NUM_FEASIBLE_REGISTERS)
	sys.exit(0)
else:
	print "Please enter valid allocation scheme: 0 or 1 or 2"

print shape(code, register_freqs)
