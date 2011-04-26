#!/usr/bin/python
import sys
import os
from UserString import MutableString

""" This python script recursively parses a simple context free grammar and generates ILOC code for it
Author: Vaibhav Verma

Grammar: 

	Program ::= Stmtlist .
	Stmtlist ::= Stmt NextStmt
	NextStmt := ; Stmtlist | epsilon
	Stmt ::= Assign | Print
	Assign ::= ID = Expr
	Print ::= ! ID
	Expr ::= + Expr Expr |
			- Expr Expr |
			* Expr Expr |
			ID |
			ICONST """

def print_usage():
	print "Usage: python rec.py <input-string>"
	sys.exit()


if len(sys.argv) < 2:
	print "Please enter an input string to generate ILOC code for"
	print_usage()

input_string = sys.argv[1]

token = MutableString('')

def get_token():
	global token
	return str(token)


def next_token():
	global input_string
	global token

	if not input_string:
		token = MutableString('\0')
		return str(token)


	token = MutableString(input_string[0])
	input_string = input_string[1:]


"""Helpers for the Parser"""

def is_id(token):
	if len(token) != 1:
		raise ValueError, "Token is longer than an alphabet. Please fix."
	return token.isalpha()

def is_const(token):
	if len(token) != 1:
		raise ValueError, "Token is longer than an alphabet. Please fix."
	return token.isdigit()

REGISTER_PREFIX = 'r'
symbol_table = {}

"""Inserts a variable, register pair into the symbol table."""
def insert(variable, register):
	#Sanity Checks
	if len(variable) != 1:
		raise ValueError, "Variable '%s' cannot be inserted because it's longer than a character" %(variable)

	if not register.startswith(REGISTER_PREFIX):
		raise ValueError, "Register '%s' cannot be inserted into the symbol table, because it's invalid." %(register)
	
	symbol_table[variable] = int(register.strip(REGISTER_PREFIX))
	

"""Looks up the current variable in the symbol table."""
def lookup(variable): 
	if symbol_table.has_key(variable):
		return REGISTER_PREFIX + str(symbol_table[variable])
	raise ValueError, "Variable '%s' does not exist in the symbol table '%s'." % (variable, symbol_table)


""" Returns the next free virtual register. """
def next_register():
	if not symbol_table:
		max_register=0
	else: 
		max_register = max(map(lambda x: x[1], symbol_table.items()))

	return REGISTER_PREFIX + str(max_register + 1)

""" Recursive Methods for Input Parsing """

""" Program -> StmtList . """
def program():
	if is_id(get_token()) or get_token() == '!':
		print "loadI \t1020 => r0 //for printing purposes"
		stmt_list()
		next_token()
	if get_token() == '.':
		return None

	raise ValueError, "Input given has a syntax error id or ! expected, '%s' given " % (get_token())

""" StmtList -> Stmt NextStmt """
def stmt_list():
	if is_id(get_token()) or get_token() == '!':
		stmt()
		next_stmt()
	
		return None
	raise ValueError, "Input given has a syntax error id or ! expected, '%s' given " % (get_token())

""" NextStmt -> ; StmtList """

def next_stmt():
	global input_string

	if get_token() == ';':
		next_token()
		stmt_list()

		return None

	if get_token() == '\0':
		return None


	print "Input: ", input_string

	raise ValueError, "Input has given a syntax error ; or epsilon expected, '%s' given" % (get_token())


"""Stmt -> Assign | Print """
def stmt():
	if is_id(get_token()):
		return assign()

	if get_token() == '!':
		return print_()

	raise ValueError, "Input given has a syntax error id or ! expected, '%s' given " % (get_token())
		
"""Assign -> ID = Expr """
def assign():
	if is_id(get_token()):
		variable = get_token()
		next_token()

		if get_token() != '=':
			raise ValueError, "Input given has a syntax error '=' expected, '%s' given" % (get_token()) 

		next_token()

		register = expr()
		insert(variable, register)

		return None
	raise ValueError, "Input given has a syntax error id expected, '%s' given " % (get_token())

"""Print -> !id """
def print_():
	if get_token() == '!':
		next_token()
		if is_id(get_token()):
			register = lookup(get_token())

			print "store \t%s => r0 \noutput \t1020 " % (register)
			next_token()
			return None
		raise ValueError, "Input given has a syntax error id expected, '%s' given" % (get_token())
	
	raise ValueError, "Input given has a syntax error ! expected, '%s' given" % (get_token())

"""Expr -> + Expr Expr | - Expr Expr | * Expr Expr | id | iconst"""
def expr():
	if is_id(get_token()):
		reg = lookup(get_token())
		next_token()
		return reg

	if is_const(get_token()):
		reg = next_register()
		print "loadI\t%s => %s" %(get_token(), reg)
		next_token()
		return reg

	if get_token() in '+-*':

		op = get_token()

		next_token()
		
		reg1 = expr()
		reg2 = expr()

		newreg = next_register()

		instruction_table = {'+': 'add', '-': 'sub', '*': 'mult'}
		print "%s\t %s, %s => %s" % (instruction_table[op], reg2, reg1, newreg)

		insert(newreg.strip(REGISTER_PREFIX), newreg)

		return newreg

	raise ValueError, "Input has given a syntax error id or const or operator (+, -, *) expected, '%s' given" % (get_token())

next_token()

try: 
	program()
except ValueError, e:
	print "%s" % (e)
