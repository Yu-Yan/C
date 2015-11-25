#ifndef _Hash_H

struct ListNode;
typedef struct ListNode *Position;
typedef Position *List;

struct HashTbl;
typedef struct HashTbl *HashTable;

typedef unsigned int Index;

HashTable InitializeTable(int TablesSize);
void Insert(char *str, HashTable T);
Position Find(char *str, HashTable T);
void Delete(char *str, HashTable T);
Index hash(char *str, int TableSize);

struct ListNode
{
	char *str;
	Position next;
};

struct HashTbl
{
	int size;
	List lists;
};

#endif
