def avg(list):
	return sum(list)/float(len(list))

ls = []
for line in open('buffer'):
	ls.append(int(line))

print ls, " Average: ", avg(ls)	
