#ifndef _Queue_H


struct QueueRecord;


typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DestroyQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(int x, Queue Q);
int Dequeue(Queue Q);
int Front(Queue Q);

#endif

struct QueueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	int *array;
};
