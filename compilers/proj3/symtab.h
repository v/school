/**********************************************
        CS415  Compilers  Project2
**********************************************/

#ifndef SYMTAB_H
#define SYMTAB_H

/** This function provides a simple single-level symbol table interface implemented as an unordered singly linked list. */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* extern void * malloc(int size); */

typedef struct st_entry {
	const char *key;
	char *type;
	int reg;
	int offset;
	struct st_entry *next;
} st_entry;

int insert(const char *id, char *type, int offset);

int set_reg(const char *id, int reg);

int get_reg(const char *id);

int get_offset(const char *id);

char *get_type(const char *id);

void print_list();

void clear_regs();
void load_regs();

void print_st_entry(st_entry *ptr);



#endif
