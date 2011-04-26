/**********************************************
        CS415  Compilers  Project2
**********************************************/

#include "symtab.h"

st_entry *st_head = NULL;

int
insert(const char *id, char *type)
{
	if(lookup(id))
		return 0;
	/* Create node */
	st_entry *new_node = malloc(sizeof(st_entry));	
	new_node->key = id;
	new_node->value = type;

	/* Append to the list */
	new_node->next = st_head;
	st_head = new_node;

	return 1;
}

char *
lookup(const char *id)
{
	st_entry *ptr = st_head;
	while(ptr)
	{
		if(!strcmp(ptr->key, id))
		{
			return ptr->value;
		}

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
	sprintf(buffer, "r%d", register_count++);
	return (void *) buffer;
}

void
print_list()
{
	st_entry *ptr = st_head;
	while(ptr)
	{
		printf("Key: %s - Value: %s \n", ptr->key, ptr->value);
		ptr = ptr->next;
	}
}
