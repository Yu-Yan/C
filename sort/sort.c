#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void InsertSort(int A[], int N);
void PrintArray(int *A, int N);
void ShellSort(int A[], int N);
void HeapSort(int A[], int N);
void PutThis(int A[], int i, int N); // to make heap
void Merge(int A[], int TmpArray[], int left, int right, int end);// merge two sorted array to one
void Msort(int A[], int TmpArray[], int left, int right);// recursively sort all parts of the array
void MergeSort(int A[], int N);
void QuickSort(int A[], int N);
void Qsort(int A[], int left, int right);
int Middle3(int A[], int left, int right);

int main(void)
{
	int *a, b;
	a = malloc(sizeof(int) * SIZE);
	b = 0;
	while (b < SIZE)
		a[b++] = rand();
	PrintArray(a, SIZE);
	QuickSort(a, SIZE);
	PrintArray(a, SIZE);

	return 0;
}


void PrintArray(int *A, int N)
{
	int b;
	FILE *fp;
	fp = fopen("output.txt", "a+");
	fprintf(fp, "PrintArray:");
	for (b = 0; b < N; b++)
		fprintf(fp, "%d ", A[b]);
	fprintf(fp, "\n\n");
	fclose(fp);
}

void InsertSort(int A[], int N)
{
	int j, p;
	int tmp;
	for (p = 1; p < N; p++)
	{
		tmp = A[p];
		for (j = p; j > 0 && A[j - 1] > tmp; j--)
			A[j] = A[j - 1];
		A[j] = tmp;
	}
}

void ShellSort(int A[], int N)
{
	int i, j, increment;
	int tmp;
	for (increment = N / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < N; i++)
		{
			tmp = A[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (tmp < A[j - increment])
					A[j] = A[j - increment];
				else
					break;
			}
			A[j] = tmp;
		}
	}
}


void PutThis(int A[], int i, int N)
{
	int child;
	int tmp;
	for (tmp = A[i]; 2 * i + 1 < N; i = child)
	{
		child = 2 * i + 1;
		if (child != N - 1 && A[child] < A[child + 1])
			child++;
		if (A[child] > tmp)
			A[i] = A[child];
		else
			break;
	}
	A[i] = tmp;
}

void HeapSort(int A[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)
		PutThis(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		int tmp;
		tmp = A[i];
		A[i] = A[0];
		A[0] = tmp;
		PutThis(A, 0, i);
	}
}

void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int end)
{
	int Lend, i, j, k;
	Lend = Rpos - 1;
	i = k = Lend;
	j = Rpos;
	while (i <= Lend && j <= end)
	{
		if (A[i] < A[j])
			TmpArray[k++] = A[i++];
		else
			TmpArray[k++] = A[j++];
	}
	while (i <= Lend)
		TmpArray[k++] = A[i++];
	while (j <= end)
		TmpArray[k++] = A[j++];
	for (i = end; i >= Lpos; i--)
		A[i] = TmpArray[i];
}

void Msort(int A[], int TmpArray[], int left, int right)
{
	int center;
	if (left < right)
	{
		center = (left + right) / 2;
		Msort(A, TmpArray, left, center);
		Msort(A, TmpArray, center + 1, right);
		Merge(A, TmpArray, left, center + 1, right);
	}
}

void MergeSort(int A[], int N)
{
	int *TmpArray;
	TmpArray = malloc(sizeof(int)*N);
	if (TmpArray != NULL)
	{
		Msort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
	{
		printf("error MergeSort, out of space\n");
		exit(0);
	}
}

void QuickSort(int A[], int N)
{
	Qsort(A, 0, N - 1);
}

void Qsort(int A[], int left, int right)
{
	int i, j;
	int tmp;
	int pivot;
	if (left + 3 <= right)
	{
		pivot = Middle3(A, left, right);
		i = left;
		j = right - 1;
		for ( ; ; )
		{
			while (A[++i] < pivot);
			while (A[--j] > pivot);
			if (i < j)
			{
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
			else
				break;
		}
		tmp = A[i];
		A[i] = pivot;
		A[right - 1] = tmp;

		Qsort(A, left, i - 1);
		Qsort(A, i, right);
	}
	else
	{
		for (i = left + 1; i <= right; i++)
		{
			tmp = A[i];
			for (j = i - 1; j >= 0; )
			{
				if (A[j] > tmp)
				{
					A[j + 1] = A[j];
					j--;
				}
				else
					break;
			}
			A[j + 1] = tmp;
		}
	}
}

int Middle3(int A[], int left, int right)
{
	int pivot, tmp;
	int center;
	center = (left + right) / 2;
	pivot = A[center];
	if (A[left] > A[center])
	{
		tmp = A[left];
		A[left] = A[center];
		A[center] = tmp;
	}
	if (A[left] > A[right])
	{
		tmp = A[left];
		A[left] = A[right];
		A[right] = tmp;
	}
	if (A[center] > A[right])
	{
		tmp = A[center];
		A[center] = A[right];
		A[right] = tmp;
	}
	A[center] = A[right - 1];
	A[right - 1] = pivot;
	return pivot;
}

