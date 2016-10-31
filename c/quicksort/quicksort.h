/* *******************************************
**  quicksort.h: See the quicksort.h file   **
**    By Alejandro Linarez Rangel           **
******************************************* */

#ifndef __ALGORITHMS_QUICKSORT_FUNCTIONS_H__
#define __ALGORITHMS_QUICKSORT_FUNCTIONS_H__ 1

/* Uses C11 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*algorithm_qs_function)(void*, void*, size_t);
typedef int (*algorithm_qs_fpivot)(void*, size_t, int, int, algorithm_qs_function, algorithm_qs_function);

void algorithm_quicksort(
	void* array,
	size_t element_size,
	size_t array_size,
	algorithm_qs_function compare_function
);

void algorithm_quicksort_s(
	void* array,
	size_t element_size,
	size_t array_size,
	algorithm_qs_function compare_function,
	algorithm_qs_function swap_function
);

void algorithm_quicksort_sp(
	void* array,
	size_t element_size,
	size_t array_size,
	algorithm_qs_function compare_function,
	algorithm_qs_function swap_function,
	algorithm_qs_fpivot select_pivot_function
);

void algorithm_quicksort_core(
	void* array,
	size_t element_size,
	int lower,
	int higher,
	algorithm_qs_function compare_function,
	algorithm_qs_function swap_function,
	algorithm_qs_fpivot select_pivot_function
);

int algorithm_quicksort_fpivot(
	void* array,
	size_t element_size,
	int lower,
	int higher,
	algorithm_qs_function less_than,
	algorithm_qs_function swap
);

int algorithm_quicksort_fswap(
	void* el_a,
	void* el_b,
	size_t element_size
);

#ifdef __cplusplus
}
#endif

#endif /* ~__ALGORITHMS_QUICKSORT_FUNCTIONS_H__ */


