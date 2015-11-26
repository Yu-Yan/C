#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

#define NUM 5

int main(void)
{
	Tree T;
	int n = 0;
	FILE *fp;
	fp = fopen("output.txt", "a+");

	T = CreateTree(0);
	PrintTree(fp, T);

	while (n++ < NUM)
		T = Insert(rand(), T);
	PrintTree(fp, T);

	T = Insert(100, T);
	PrintTree(fp, T);

	T = Insert(110, T);
	PrintTree(fp, T);

	T = Insert(120, T);
	PrintTree(fp, T);

	T = Delete(41, T);
	PrintTree(fp, T);

	T = Delete(26500, T);
	PrintTree(fp, T);

	T = Delete(26500, T);
	PrintTree(fp, T);

	fclose(fp);
	return 0;
}