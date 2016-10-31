#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void bubblesort(int * A, int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i;j++)
		{
			if(A[j] < A[j-1])
			{
				int temp = A[j]; 
				A[j] = A[j-1];
				A[j-1] = temp;
			}
		}
	}
}

int check_sorted(int * A, int size)
{
	for(int i=1;i<size;i++)
		if(A[i] < A[i-1])
			return 0;

	return 1;
}

void test_bubblesort()
{
	int A[100];

	for(int i=0;i<100;i++)
		A[i] = rand() % 10;

	bubblesort(A, 100);

	assert(check_sorted(A, 100));
}

int main()
{
	time_t t;

	srand((unsigned) time(&t));

	test_bubblesort();

	return 0;
}