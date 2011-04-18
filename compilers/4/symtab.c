/**********************************************
        CS415  Compilers  Project2
**********************************************/

#include "symtab.h"

extern void * malloc(int size);

st_entry *st_head = NULL;

void *
insert(char *id)
{
	/* Create node */
	st_entry *new_node = malloc(sizeof(st_entry));	
	new_node->key = id;
	new_node->value = get_next_register();

	/* Append to the list */
	new_node->next = st_head;
	st_head = new_node;

	return st_head;
}

void *
lookup(char *id)
{
	st_entry *ptr = st_head;
	while(ptr)
	{
		if(!strcmp(ptr->key, id))
			return ptr->value;

		ptr = ptr->next;
	}
	return NULL;
}

int register_count = 0;

/** Returns a dynamically allocated copy of the next register value. */
void *
get_next_register()
{
	int size = (register_count/10) + 1;
	char *buffer = malloc(size*sizeof(char));
	return (void *)sprintf(buffer, "r%d", register_count++);
}
