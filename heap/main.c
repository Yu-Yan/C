#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void)
{
	PriorityQueue H;
	int a = 0;
	FILE *f;
	f = fopen("output.txt", "w+");
	H = CreateHeap(13);
	fprintf(f, "IsEmpty(H):%d  IsFull(H):%d\n", IsEmpty(H), IsFull(H));
	while (a++ < 13)
		Insert(13-a, H);
	fprintf(f, "IsEmpty(H):%d  IsFull(H):%d\n", IsEmpty(H), IsFull(H));
	a = 0;
	while (a++ < 13)
		fprintf(f, "%d ",DeleteMin(H));
	MakeEmpty(H);
	fprintf(f, "\nIsEmpty(H):%d  IsFull(H):%d\n", IsEmpty(H), IsFull(H));
	return 0;
}