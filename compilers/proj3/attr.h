/**********************************************
        CS415  Compilers  Project2
**********************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef ATTR_H
#define ATTR_H

typedef struct {   
        int targetRegister;
        } regInfo;

typedef struct { 
	char *str; 
	int num;
	char *type;
} tokentype;

typedef struct attributes { tokentype token; char *type; } attributes;

typedef struct strnode { char *value; struct strnode *next; } strnode;

typedef struct strlist { strnode *head; } strlist;

char *strdup(const char *s);

char *mystrcat(const char *a, const char *b);


void strlist_new(strlist *s);

void strlist_insert(strlist *s, char *var);

char * strlist_map(strlist *s, int (*fn)(const char *, char*), char *value);

int starts_with(char *haystack, char *needle);

#endif
