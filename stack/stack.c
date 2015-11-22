#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

Stack CreateStack(void)
{
	Stack S;
	S = malloc(sizeof(struct Node));
	if (S == NULL)
	{
		printf("error CreateStack, out of space\n");
		exit(1);
	}
	S->element = 9999;
	S->next = NULL;
	return S;
}

int IsEmpty(Stack S)
{
	return S->next == NULL;
}

void MakeEmpty(Stack S)
{
	PtrToNode tmp, p;
	tmp = S->next;
	S->next = NULL;
	while (tmp != NULL)
	{
		p = tmp->next;
		free(tmp);
		tmp = p;
	}
}

void Push(int x, Stack S)
{
	PtrToNode p;
	p = malloc(sizeof(struct Node));
	if (p == NULL)
	{
		printf("error Push, out of space\n");
	}
	p->element = x;
	p->next = S->next;
	S->next = p;
}

int Top(Stack S)
{
	if (IsEmpty(S))
	{
		printf("\nerror Top, empty Stack\n");
		exit(0);
	}
	return S->next->element;
}

int Pop(Stack S)
{
	if (IsEmpty(S))
	{
		printf("\nerror Pop, empty Stack\n");
		exit(0);
	}
	PtrToNode p;
	p = S->next;
	S->next = p->next;
	return p->element;
}

