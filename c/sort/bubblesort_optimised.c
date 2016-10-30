//
// Optimized implementation of Bubble sort
// https://en.wikipedia.org/wiki/Bubble_sort
// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void _sortingProvider(int arr[])
{
  int arraySize = sizeof(arr);
  if(arraySize<=0)
  {
    printf("Nothing to sort.\n", );
    return 0;
  }
  int n = arraySize/sizeof(arr[0]);
  printf("Sample Data: \n");
  printArray(arr, n);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);

}

// Driver program to test above functions
int main()
{
  _sortingProvider({64, 34, 25, 12, 22, 11, 90});
  _sortingProvider({-64, -34, -25, -12, -22, -11, -90});
  _sortingProvider({64, -34, 25, -12, 22, 11, -90});
  _sortingProvider({100});
  _sortingProvider({});

  return 0;
}
