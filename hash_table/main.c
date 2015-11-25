#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void PrintHashTable(HashTable T);

int main(void)
{
	HashTable T;
	T = InitializeTable(7);
	PrintHashTable(T);
	Insert("hello world", T);
	Insert("world hello", T);
	Insert("orange", T);
	Insert("crossfire", T);
	Insert("facsdfook", T);
	Insert("fawerbkoo", T);
	Insert("fac323koooooo9999", T);
	Insert("fawerbkoo", T);
	Insert("fac323koo", T);
	Insert("fa1212bkoo", T);
	Insert("fatrtbkoo", T);
	Insert("f2ebkoo", T);
	Insert("fa88bkoo", T);
	Insert("facebkpp", T);
	Insert("facebklo", T);
	Insert("facemmoo", T);
	Insert("face.,oo", T);
	Insert("face112koo", T);
	Insert("facebASDQWEo", T);
	Insert("facQWQWkoo", T);
	PrintHashTable(T);
	Delete("fac323koooooo9999", T);
	PrintHashTable(T);
	return 0;
}


//for test
void PrintHashTable(HashTable T)
{
	FILE *f;
	f = fopen("output.txt", "a+");
	fprintf(f, "---PrintHashTable---");
	Position tmp;
	int a;
	a = 0;
	while (a < T->size)
	{
		tmp = T->lists[a];
		fprintf(f, "\n%d: ", a);
		while (tmp != NULL)
		{
			fprintf(f, "%s - ", tmp->str);
			tmp = tmp->next;
		}
		a++;
	}
	fprintf(f, "\n---PrintHashTable(end)---\n\n");
}