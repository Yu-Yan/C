#ifndef _Avl_H

struct TreeNode;
typedef struct TreeNode *Tree;

Tree CreateTree(int firstValue);
Tree Insert(int x, Tree T);
Tree Delete(int x, Tree T);
Tree SingleRotateLeft(Tree T);
Tree DoubleRotateLeft(Tree T);
Tree SingleRotateRight(Tree T);
Tree DoubleRotateRight(Tree T);
int Height(Tree T);
void PrintT(FILE *fp, Tree T);
void PrintTr(FILE *fp, Tree T);
void PrintTree(FILE *fp, Tree T);

struct TreeNode
{
	int element;
	Tree left;
	Tree right;
	int height;
};

#endif
