/**********************************************
        CS415  Compilers  Project2
**********************************************/

#include "symtab.h"
#include "instrutil.h"

st_entry *st_head = NULL;

int
insert(const char *id, char *type, int offset)
{
	if(get_type(id))
		return 0;
	/* Create node */
	st_entry *new_node = malloc(sizeof(st_entry));	
	new_node->key = id;
	new_node->offset = offset;

	/* Append to the list */
	new_node->next = st_head;
	st_head = new_node;

	return 1;
}

int
set_reg(const char *id, int reg)
{
	st_entry *ptr = st_head;
	while(ptr)
	{
		if(!strcmp(ptr->key, id))
		{
			ptr->reg = reg;
			return 1;
		}

		ptr = ptr->next;
	}
	return 0;
}

int
get_reg(const char *id)
{
	st_entry *ptr = st_head;
	while(ptr)
	{
		if(!strcmp(ptr->key, id))
		{
			return ptr->reg;
		}

		ptr = ptr->next;
	}
	return 0;
}


int
get_offset(const char *id)
{
	st_entry *ptr = st_head;
	while(ptr)
	{
		if(!strcmp(ptr->key, id))
		{
			return ptr->offset;
		}

		ptr = ptr->next;
	}
	return 0;
}

char *
get_type(const char *id)
{
	st_entry *ptr = st_head;
	while(ptr)
	{
		if(!strcmp(ptr->key, id))
		{
			return ptr->type;
		}

		ptr = ptr->next;
	}
	return NULL;
}

void
print_list()
{
	st_entry *ptr = st_head;
	while(ptr)
	{
		print_st_entry(ptr);
		ptr = ptr->next;
	}
}

void
print_st_entry(st_entry *ptr)
{
	printf("Key: %s - Type: %s Register: %d Offset %d \n", ptr->key, ptr->type, ptr->reg, ptr->offset);
}

void
clear_regs()
{
	st_entry *ptr = st_head;
	emitComment("Clear all registers because basic block is ending. \n");
	while(ptr)
	{
		//storeAI reg => r0, offset
		emit(NOLABEL, STOREAI, ptr->reg, 0, ptr->offset);
		ptr = ptr->next;
	}
}

void
load_regs()
{
	st_entry *ptr = st_head;
	emitComment("Load all registers because basic block is starting. \n");
	while(ptr)
	{
		//loadAI r0, offset => reg
		if(ptr->reg)
			emit(NOLABEL, LOADAI, 0, ptr->offset, ptr->reg);
		ptr = ptr->next;
	}
}
