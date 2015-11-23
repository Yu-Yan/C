#ifndef _SearchTree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree CreateTree(int x);
SearchTree MakeEmpty(SearchTree T);
Position Find(int x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int x, SearchTree T);
SearchTree Delete(int x, SearchTree T);
int Retrieve(Position p);
void PrintTree(FILE *f, SearchTree T);

#endif

struct TreeNode
{
	int element;
	SearchTree Left;
	SearchTree Right;
};
