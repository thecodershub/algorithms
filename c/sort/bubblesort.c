//
// Bubble sort implementation in C
// https://en.wikipedia.org/wiki/Bubble_sort
// Time Complexity : O(n^2)

#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
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
