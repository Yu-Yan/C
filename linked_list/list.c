#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#define HEADER 9999

int IsEmpty(List L)
{
	return L->next == NULL;
}

int IsLast(Position p)
{
	return p->next == NULL;
}

void Insert(int x, List L, Position p)
{
	Position tmp;
	tmp = malloc(sizeof(struct Node));
	if (tmp == NULL)
		exit(1);
	tmp->element = x;
	tmp->next = p->next;
	p->next = tmp;
}

void Delete(int x, List L)
{
	Position tmp, p;
	tmp = L;
	while (tmp->next != NULL && tmp->next->element != x)
		tmp = tmp->next;
	if (tmp->next == NULL)
	{
		printf("%d not found, cannot delete %d", x, x);
		exit(1);
	}
	p = tmp->next;
	tmp->next = p->next;
	free(p);
}

void DeleteAll(List L)
{
	Position tmp, p;
	p = L;
	while (p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
}

Position Find(int x, List L)
{
	Position tmp;
	tmp = L;
	while (tmp != NULL && tmp->element != x)
		tmp = tmp->next;
	return tmp;
}

void Change(int x, List L, Position p)
{
	p->element = x;
}

List CreateList(List L)
{
	L = malloc(sizeof(struct Node));
	L->element = HEADER;
	L->next = NULL;
	return L;
}
