#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int IsEmpty(PriorityQueue H)
{
	return H->size == 0;
}

int IsFull(PriorityQueue H)
{
	return H->size == H->capacity;
}

PriorityQueue CreateHeap(int MaxElements)
{
	PriorityQueue H;
	H = malloc(sizeof(struct HeapStruct));
	if (H == NULL)
	{
		printf("error CreateHeap, out of space\n");
		exit(0);
	}
	H->capacity = MaxElements;
	H->size = 0;
	H->array = malloc(sizeof(int)*(MaxElements + 1));
	if (H->array == NULL)
	{
		printf("error CreateHeap, out of space\n");
		exit(0);
	}
	H->array[0] = 0;
	return H;
}

void Insert(int x, PriorityQueue H)
{
	int a;
	if (H == NULL || IsFull(H))
	{
		printf("Heap is not initialized OR is already full\n");
		exit(0);
	}
	for (a = ++H->size; x < H->array[a / 2]; a /= 2)
	{
		H->array[a] = H->array[a / 2];
	}
	H->array[a] = x;
}

int DeleteMin(PriorityQueue H)
{
	int a, b, tmp, child;
	if (IsEmpty(H))
	{
		printf("error DeleteMin, Heap is empty\n");
		exit(0);
	}
	b = H->array[1];
	tmp = H->array[H->size--];
	for (a = 1; a*2 <= H->size; a = child)
	{
		child = a * 2;
		if (child + 1 <= H->size && H->array[child] > H->array[child + 1])
			child += 1;
		if (tmp > H->array[child])
			H->array[a] = H->array[child];
		else
			break;
	}
	H->array[a] = tmp;
	return b;
}

void MakeEmpty(PriorityQueue H)
{
	while (!IsEmpty(H))
		DeleteMin(H);
}