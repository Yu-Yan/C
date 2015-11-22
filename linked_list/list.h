#ifndef _List_H

struct Node
{
	int element;
	struct Node *next;
};

typedef struct Node *List;
typedef List Position;

int IsEmpty(List L);
int IsLast(Position p);
void Insert(int x, List L, Position p);
void Delete(int x, List L);
void DeleteAll(List L);
Position Find(int x, List L);
void Change(int x, List L, Position p);
List CreateList(List L);

#endif

