#ifndef _Heap_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
PriorityQueue CreateHeap(int MaxElements);
void Insert(int x, PriorityQueue H);
int DeleteMin(PriorityQueue H);
void MakeEmpty(PriorityQueue H);

#endif

struct HeapStruct
{
	int capacity;
	int size;
	int *array;
};