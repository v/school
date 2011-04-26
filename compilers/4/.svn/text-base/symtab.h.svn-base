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
	char *value;
	struct st_entry *next;
} st_entry;

int insert(const char *id, char *type);

char * lookup(const char *id);

void * get_next_register();

void print_list();



#endif
