#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <string.h>


Index hash(char *str, int TableSize)
{
	Index hashVal = 0;
	while (*str != '\0')
		hashVal = (hashVal << 5) + *str++;
	return hashVal % TableSize;
}


HashTable InitializeTable(int TableSize)
{
	HashTable T;
	int a = 0;
	T = malloc(sizeof(struct HashTbl));
	if (T == NULL)
	{
		printf("error InitializeTable, out of space\n");
		exit(0);
	}
	T->size = TableSize;
	T->lists = malloc(sizeof(Position)*TableSize);
	if (T->lists == NULL)
	{
		printf("error InitializeTable, out of space\n");
		exit(0);
	}
	while (a < TableSize)
		T->lists[a++] = NULL;
	return T;
}

void Insert(char *str, HashTable T)
{
	Position p;
	Index n;
	p = malloc(sizeof(struct ListNode));
	if (p == NULL)
	{
		printf("error Insert, out of space(initialize p)\n");
		return;
	}
	if (Find(str, T) == NULL)
	{
		n = hash(str, T->size);
		p->str = malloc(sizeof(char)*(strlen(str) + 1));
		if (p->str == NULL)
		{
			printf("error Insert, out of space, initialize p->str\n");
			exit(0);
		}
		p->str = str;
		p->next = T->lists[n];
		T->lists[n] = p;
	}
	else
		printf("\"%s\" is already in hashtable, can not Insert again.\n", str);
}

Position Find(char *str, HashTable T)
{
	Position tmp;
	Index n = hash(str, T->size);
	tmp = T->lists[n];
	while (tmp != NULL && strcmp(str, tmp->str) != 0)
		tmp = tmp->next;
	return tmp;
}

void Delete(char *str, HashTable T)
{
	Position p, tmp;
	Index n = hash(str, T->size);
	p = Find(str, T);
	if (p == NULL)
	{
		printf("%s not found, can not delete\n", str);
		return;
	}
	tmp = T->lists[n];
	while (tmp->next != p)
		tmp = tmp->next;
	tmp->next = p->next;
	free(p);
}