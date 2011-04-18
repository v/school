/**********************************************
        CS415  Compilers  Project2
**********************************************/

#ifndef SYMTAB_H
#define SYMTAB_H

/** This function provides a simple single-level symbol table interface implemented as an unordered singly linked list. */


#include <stdio.h>
#include <string.h>

/* extern void * malloc(int size); */

typedef struct st_entry {
	char *key;
	void *value;
	struct st_entry *next;
} st_entry;

void * insert(char *id);

void * lookup(char *id);

void * get_next_register();



#endif
