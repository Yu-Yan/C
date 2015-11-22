#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void)
{
	List L;
	int a;
	Position p;
	FILE *f;
	f = fopen("output.txt", "w+");
	L = CreateList(L);
	fprintf(f, "IsEmpty(L) = %d\n",IsEmpty(L));
	for (a=0; a<10; a++)
		Insert(a*a-6*a, L, L);
	fprintf(f, "IsEmpty(L) = %d\n",IsEmpty(L));
	p = L;
	while (p != NULL)
	{
		fprintf(f, "%d ", p->element);
		p = p->next;
	}
	Delete(0, L);
	fprintf(f, "\n");
	p = L;
	while (p != NULL)
	{
		fprintf(f, "%d ", p->element);
		p = p->next;
	}
	p = Find(0, L);
	fprintf(f, "\n0 is at %d\n", p);
	DeleteAll(L);
	fprintf(f, "IsEmpty(L) = %d\n",IsEmpty(L));
	fclose(f);
	return 0;
}
