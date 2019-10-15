#include<stdio.h>
#include <string.h>
#include <assert.h>
#define NLIMIT 100000

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot element
    int i = (low - 1);
	int j;  
  
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot element
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int p = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, p - 1); 
        quickSort(arr, p + 1, high); 
    } 
} 


int checkQuickSort(int arr[], int n)
{
    int i;
    quickSort(arr,0,n);
    for(i = 1; i < n; ++i)
    {
        if(arr[i-1] > arr[i])
        {
            return 1;
        }
    }
    return 0;
}

int testQuickSort()
{
    int i, j, arr[NLIMIT];
    /* Test #1: All 0s */

    for(i = 0; i < NLIMIT; ++i)
    {
        arr[i] = 0;
    }
    assert(checkQuickSort(arr, NLIMIT) == 0);

    /* Test #2: Range [0, NLIMIT) in increasing order */

    for(i = 0; i < NLIMIT; ++i)
    {
        arr[i] = i;
    }
    assert(checkQuickSort(arr, NLIMIT) == 0);

    /* Test #3: Range [1, NLIMIT] in decreasing order */
    j = NLIMIT;
    for(i = 0; i < NLIMIT; ++i)
    {
        arr[i] = j--;
    }
    assert(checkQuickSort(arr, NLIMIT) == 0);

    return 0;
}

int main()
{
    testQuickSort();
    return 0;
}
