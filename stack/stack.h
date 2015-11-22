#ifndef _Stack_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

Stack CreateStack(void);
void DestroyStack(Stack S);
void MakeEmpty(Stack S);
int IsEmpty(Stack S);
void Push(int x, Stack S);
int Top(Stack S);
int Pop(Stack S);

#endif

struct Node
{
	int element;
	PtrToNode next;
};
