/**********************************************
        CS415  Compilers  Project2
**********************************************/


#include "attr.h" 

/** Duplicates a string and returns a dynamically allocated copy. */
char *
strdup(const char *s)
{
	char *rv = malloc(sizeof(char) * strlen(s) + 1);
	strcpy(rv, s);
	return rv;
}

/** Concatenates two strings, and returns a dynamically allocated copy. */

char *
mystrcat(const char *a, const char *b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);

	char *rv = malloc(sizeof(char)* (len_a+len_b+1));
	int i=0;
	while ( i < len_a)
		rv[i++] = a[i];

	while ( i < len_a + len_b)
		rv[i++] = b[i-len_a];

	rv[i] = 0;

	return rv;
}

void
strlist_new(strlist *s)
{
	s->head = NULL;
}

void
strlist_insert(strlist *s, char *var)
{
	strnode *n = malloc(sizeof(strnode));
	n->value = var;

	n->next = s->head;
	s->head = n;
}

char *
strlist_map(strlist *s, int (*fn)(const char *, char *), char *value)
{
	strnode *ptr = s->head;

	while(ptr)
	{
		if(!(fn)(ptr->value, value))
			return ptr->value;
		ptr = ptr->next;
	}
	return NULL;
}

int
starts_with(char *haystack, char *needle)
{
	int len = strlen(needle);
	int i=0;
	while (i < len)
		if(needle[i++] != haystack[i])
			return 0;
	return 1;
}
