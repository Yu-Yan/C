#include <stdio.h>
#include <stdlib.h>
#include "SearchTree.h"



SearchTree CreateTree(int x)
{
	SearchTree T;
	T = malloc(sizeof(struct TreeNode));
	T->element = x;
	T->Left = NULL;
	T->Right = NULL;
	return T;
}

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		T->Left = MakeEmpty(T->Left);
		T->Right = MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(int x, SearchTree T)
{
	if (T == NULL)
	{
		printf("\nx not found\n");
		return NULL;
	}
	if (T->element == x)
		return T;
	else if (x < T->element)
		return Find(x, T->Left);
	else
		return Find(x, T->Right);
}

Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	SearchTree tmp;
	tmp = T;
	while (tmp->Left != NULL)
		tmp = tmp->Left;
	return tmp;
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}

SearchTree Insert(int x, SearchTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(struct TreeNode));
		if (T == NULL)
		{
			printf("error Insert, out of space\n");
			exit(0);
		}
		T->element = x;
		T->Right = T->Left = NULL;
	}
	else if (x < T->element)
		T->Left = Insert(x, T->Left);
	else if (x > T->element)
		T->Right = Insert(x, T->Right);
	else;
	return T;
}

SearchTree Delete(int x, SearchTree T)
{
	Position tmpcell;
	if (T == NULL)
	{
		printf("%d not found\n", x);
		exit(0);
	}
	else if (x < T->element)
		T->Left = Delete(x, T->Left);
	else if (x > T->element)
		T->Right = Delete(x, T->Right);
	else
	{
		if (T->Left && T->Right)
		{
			tmpcell = FindMin(T->Right);
			T->element = tmpcell->element;
			T->Right = Delete(tmpcell->element, T->Right);
		}
		else if (T->Left == NULL)
		{
			tmpcell = T;
			T = T->Right;
			free(tmpcell);
		}	
		else if (T->Right == NULL)
		{
			tmpcell = T;
			T = T->Left;
			free(tmpcell);
		}
	}
	return T;
}

void PrintTree(FILE *f,  SearchTree T)
{
	static int deep = 0;
	int deepthis;
	deepthis = ++deep;
	if (T == NULL)
	{
		exit(0);
	}
	fprintf(f, "%d(%d) ", T->element, deepthis);
	if (T->Left != NULL)
		PrintTree(f, T->Left);
	deep = deepthis;
	if (T->Right != NULL)
		PrintTree(f, T->Right);
}








