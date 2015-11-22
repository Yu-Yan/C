#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
	Queue Q;
	int a, b;
	FILE *f;
	Q = CreateQueue(7);
	f = fopen("output.txt", "w+");
	fprintf(f, "IsEmpty(Q):%d  IsFull(Q):%d  Q->capacity:%d  Q->front:%d  Q->rear:%d  Q->size:%d\n",
	 IsEmpty(Q), IsFull(Q), Q->capacity, Q->front, Q->rear, Q->size);
	for (a=0; a<7; a++)
	{
		Enqueue(a+100, Q);
		fprintf(f, "IsEmpty(Q):%d  IsFull(Q):%d  Q->capacity:%d  Q->front:%d  Q->rear:%d  Q->size:%d\n", 
		IsEmpty(Q), IsFull(Q), Q->capacity, Q->front, Q->rear, Q->size);
	}
	for (a=5; a>0; a--)
	{
		Dequeue(Q);
		fprintf(f, "IsEmpty(Q):%d  IsFull(Q):%d  Q->capacity:%d  Q->front:%d  Q->rear:%d  Q->size:%d\n", 
		IsEmpty(Q), IsFull(Q), Q->capacity, Q->front, Q->rear, Q->size);
	}
	for (a=0; a<4; a++)
	{
		Enqueue(a+100, Q);
		fprintf(f, "IsEmpty(Q):%d  IsFull(Q):%d  Q->capacity:%d  Q->front:%d  Q->rear:%d  Q->size:%d\n", 
		IsEmpty(Q), IsFull(Q), Q->capacity, Q->front, Q->rear, Q->size);
	}
	return 0;
}
