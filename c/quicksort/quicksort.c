/* *******************************************
**  quicksort.c: See the quicksort.h file   **
**    By Alejandro Linarez Rangel           **
******************************************* */

#include "quicksort.h"

void algorithm_quicksort(
	void* array,
	size_t element_size,
	size_t array_size,
	algorithm_qs_function compare_function
)
{
	if(array_size <= 1)
		return;
	algorithm_quicksort_core(
		array,
		element_size,
		0,
		array_size - 1,
		compare_function,
		algorithm_quicksort_fswap,
		algorithm_quicksort_fpivot
	);
}

void algorithm_quicksort_s(
	void* array,
	size_t element_size,
	size_t array_size,
	algorithm_qs_function compare_function,
	algorithm_qs_function swap_function
)
{
	if(array_size <= 1)
		return;
	algorithm_quicksort_core(
		array,
		element_size,
		0,
		array_size - 1,
		compare_function,
		swap_function,
		algorithm_quicksort_fpivot
	);
}

void algorithm_quicksort_sp(
	void* array,
	size_t element_size,
	size_t array_size,
	algorithm_qs_function compare_function,
	algorithm_qs_function swap_function,
	algorithm_qs_fpivot select_pivot_function
)
{
	if(array_size <= 1)
		return;
	algorithm_quicksort_core(
		array,
		element_size,
		0,
		array_size - 1,
		compare_function,
		swap_function,
		select_pivot_function
	);
}

void algorithm_quicksort_core(
	void* array,
	size_t element_size,
	int lower,
	int higher,
	algorithm_qs_function compare_function,
	algorithm_qs_function swap_function,
	algorithm_qs_fpivot select_pivot_function
)
{
	int pivot = 0;
	int res = 0;

	if(lower < higher)
	{
		/* Select a pivot and sort */
		pivot = (*select_pivot_function)(
			array,
			element_size,
			lower,
			higher,
			compare_function,
			swap_function
		);
		/* Repeat at each array slice */
		algorithm_quicksort_core(
			array,
			element_size,
			lower,
			pivot,
			compare_function,
			swap_function,
			select_pivot_function
		);
		algorithm_quicksort_core(
			array,
			element_size,
			pivot + 1,
			higher,
			compare_function,
			swap_function,
			select_pivot_function
		);
	}
}

int algorithm_quicksort_fpivot(
	void* array,
	size_t element_size,
	int lower,
	int higher,
	algorithm_qs_function less_than,
	algorithm_qs_function swap
)
{
	int i = lower - 1, j = higher + 1, pivot = lower;

	while(1)
	{
		do
		{
			i++;
		} while((*less_than)(array + (i * element_size), array + (pivot * element_size), element_size));

		do
		{
			j--;
		} while((*less_than)(array + (pivot * element_size), array + (j * element_size), element_size));

		if(i >= j)
		{
			return j;
		}

		(*swap)(array + (i * element_size), array + (j * element_size), element_size);
	}
}

int algorithm_quicksort_fswap(
	void* el_a,
	void* el_b,
	size_t element_size
)
{
	void* l = malloc(element_size);
	memcpy(l, el_a, element_size);
	memcpy(el_a, el_b, element_size);
	memcpy(el_b, l, element_size);
	free(l);

	return 0;
}

