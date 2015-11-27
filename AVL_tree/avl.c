#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Tree CreateTree(int firstValue)
{
	Tree T;
	T = malloc(sizeof(struct TreeNode));
	if (T == NULL)
	{
		printf("error CreateTree, out of space\n");
		exit(0);
	}
	T->element = firstValue;
	T->height = 0;
	T->left = T->right = NULL;
	return T;
}

Tree Insert(int x, Tree T)
{
	if (T == NULL)
		T = CreateTree(x);
	else if (x < T->element)
	{
		T->left = Insert(x, T->left);
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (x < T->left->element)
				T = SingleRotateLeft(T);
			else
				T = DoubleRotateLeft(T);
		}
	}
	else if (x > T->element)
	{
		T->right = Insert(x, T->right);
		if (Height(T->right) - Height(T->left) == 2)
		{
			if (x > T->right->element)
				T = SingleRotateRight(T);
			else
				T = DoubleRotateRight(T);
		}
	}
	T->height = (Height(T->left) > Height(T->right) ? Height(T->left) : Height(T->right)) + 1;
	return T;
}

Tree SingleRotateLeft(Tree T)
{
	Tree tmp;
	tmp = T->left;
	T->left = tmp->right;
	tmp->right = T;
	T->height = (Height(T->left) > Height(T->right) ? Height(T->left) : Height(T->right)) + 1;
	tmp->height = (Height(tmp->left) > Height(tmp->right) ? Height(tmp->left) : Height(tmp->right)) + 1;
	return tmp;
}

Tree DoubleRotateLeft(Tree T)
{
	T->left = SingleRotateRight(T->left);
	T = SingleRotateLeft(T);
	return T;
}

Tree SingleRotateRight(Tree T)
{
	Tree tmp;
	tmp = T->right;
	T->right = tmp->left;
	tmp->left = T;
	T->height = (Height(T->left) > Height(T->right) ? Height(T->left) : Height(T->right)) + 1;
	tmp->height = (Height(tmp->left) > Height(tmp->right) ? Height(tmp->left) : Height(tmp->right)) + 1;
	return tmp;
}

Tree DoubleRotateRight(Tree T)
{
	T->right = SingleRotateLeft(T->right);
	T = SingleRotateRight(T);
	return T;
}

Tree Delete(int x, Tree T)
{
	if (T == NULL)
	{
		printf("%d not found, can not delete\n\n", x);
		return T;
	}
	if (x < T->element)
	{
		T->left = Delete(x, T->left);
		T->height = (Height(T->left) > Height(T->right) ? Height(T->left) : Height(T->right)) + 1;
		if (Height(T->left) - Height(T->right) == -2)
		{
			if (T->right->right)
				T = SingleRotateRight(T);
			else
				T = DoubleRotateRight(T);
		}
	}
	else if (x > T->element)
	{
		T->right = Delete(x, T->right); 
		T->height = (Height(T->left) > Height(T->right) ? Height(T->left) : Height(T->right)) + 1;
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (T->left->left)
				T = SingleRotateLeft(T);
			else
				T = DoubleRotateLeft(T);
		}
			T = SingleRotateLeft(T);
	}
	else if (x == T->element)
	{
		Tree tmp;
		if (T->left && T->right)
		{
			tmp = T->right;
			while (tmp->left != NULL)
				tmp = tmp->left;
			T->element = tmp->element;
			T->right = Delete(tmp->element, T->right);
			T->height = (Height(T->left) > Height(T->right) ? Height(T->left) : Height(T->right)) + 1;
			if (Height(T->left) - Height(T->right) == 2)
				T = SingleRotateLeft(T);
		}
		else if (T->left == NULL)
		{
			tmp = T;
			T = T->right;
			free(tmp);
		}
		else if (T->right == NULL)
		{
			tmp = T;
			T = T->left;
			free(tmp);
		}
	}
	return T;
}

int Height(Tree T)
{
	if (T == NULL)
		return -1;
	else
		return T->height;
}

void PrintT(FILE *fp, Tree T)
{
	if (T == NULL)
		fprintf(fp, "(%s)   ", "NULL");
	else
		fprintf(fp, "(%d)   ", T->element);
}

void PrintTr(FILE *fp, Tree T)
{
	if (T == NULL)
	{
		return;
	}
	fprintf(fp, "%-10d", T->element); fprintf(fp, "L"); PrintT(fp, T->left); fprintf(fp, "R"); PrintT(fp, T->right); fprintf(fp, "\n");
	PrintTr(fp, T->left);
	PrintTr(fp, T->right);
}

void PrintTree(FILE *fp, Tree T)
{
	fprintf(fp, "PrintTree:\n");
	PrintTr(fp, T);
	fprintf(fp, "\n\n");
}