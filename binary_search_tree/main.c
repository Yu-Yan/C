#include <stdio.h>
#include <stdlib.h>
#include "SearchTree.h"

int main(void)
{
	SearchTree T;
	Position p;
	FILE *f;
	int a, ctx = 0;
	f = fopen("output.txt", "w+");
	T = CreateTree(20000);
	while (ctx++ < 13)
	{
		a = rand();
		Insert(a, T);
	}
	PrintTree(f, T);
	p = Find(11478, T);
	if (p)
		fprintf(f, "\nFind(x, T):%p\tp->element:%d\n", p, p->element);
	p = FindMin(T);
	fprintf(f, "FindMin(T):%p\tp->element:%d\n", p, p->element);
	p = FindMax(T);
	fprintf(f, "FindMax(T):%p\tp->element:%d\n", p, p->element);
	Insert(20001, T);
	T = Delete(20000, T);
	PrintTree(f, T);
	fclose(f);
	return 0;
}
