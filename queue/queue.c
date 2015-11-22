#include<stdio.h>
#include<stdlib.h>
# include "queue.h"


int IsEmpty(Queue Q)
{
	return Q->size == 0;
}

int IsFull(Queue Q)
{
	return Q->size == Q->capacity;
}

Queue CreateQueue(int MaxElements)
{
	if (MaxElements < 4)
	{
		printf("capacity no less than 4\n");
		exit(1);
	}
	Queue Q;
	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
	{
		printf("error CreateQueue, Out of space\n");
		exit(1);
	}
	Q->capacity = MaxElements;
	Q->front = 0;
	Q->rear = 0;
	Q->size = 0;
	Q->array = (int *)malloc(sizeof(int)*MaxElements);
	if (Q->array == NULL)
	{
		printf("error CreateQueue, out of space\n");
		exit(1);
	}
	return Q;
}

void Enqueue(int x, Queue Q)
{
	if (IsFull(Q))
	{
		printf("Queue is full\n");
		exit(0);
	}
	Q->size++;
	Q->array[Q->rear] = x;
	if (++Q->rear == Q->capacity)
		Q->rear = 0;
}


int Front(Queue Q)
{
	return Q->array[Q->front];
}

int Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		printf("queue is empty\n");
		exit(0);
	}
	int tmp;
	tmp = Front(Q);
	if (++Q->front == Q->capacity)
		Q->front = 0;
	Q->size--;
}

void MakeEmpty(Queue Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->size = 0;
}

void DestroyQueue(Queue Q)
{
	free(Q);
}


