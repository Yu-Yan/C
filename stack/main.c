#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	Stack S;
	int a;
	FILE *f;
	f = fopen("output.txt", "w+");
	S = CreateStack();
	for (a=0; a<9; a++)
	{
		Push(a*a, S);
		fprintf(f, "%d ", Top(S));
	}
	fprintf(f, "\n");
	for (a=0; a<8; a++)
	{
		fprintf(f, "%d ", Pop(S));
	}
	fprintf(f, "\nIsEmpty(): %d", IsEmpty(S));
	MakeEmpty(S);
	fprintf(f, "\nIsEmpty(): %d", IsEmpty(S));
	fclose(f);
	return 0;
}
