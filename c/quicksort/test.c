/* *******************************************
**     test.h: QuickSort test file in C     **
**       By Alejandro Linarez Rangel        **
******************************************* */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quicksort.h"

int lessThan(void*, void*, size_t);

int quicksort_test(void)
{
	srand((unsigned int)time(NULL));

	int* array = calloc(20, sizeof(int));
	int i = 0;

	printf("Array initialized with [ ");

	for(i = 0; i < 20; i++)
	{
		array[i] = (int)(rand() % 20);
		printf("%d ", *(int*)((void*)array + (i * sizeof(int))));
	}

	printf("]\nSorting...\n");
	fflush(stdout);

	algorithm_quicksort((void*) array, sizeof(int), 20, lessThan);

	printf("Sorted array to [ ");

	for(i = 0; i < 20; i++)
	{
		printf("%d ", array[i]);
	}

	printf(" ]\n");

	return EXIT_SUCCESS;
}

int lessThan(void* a, void* b, size_t element_size)
{
	int* ai = (int*) a;
	int* bi = (int*) b;

	return (*ai) < (*bi);
}
