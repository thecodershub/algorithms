#include <stdio.h>

int main() {
  // Assumes we know how binary search works, 
  testBinSearch();
  return 0;
}

int testBinSearch() {
  // Sample to test with
  int arr[] = {-31, 0, 1, 2, 2, 4, 65, 83, 99, 782};
  int arrSize = sizeof a / sizeof a[0];
  int num = 2;
  // int index = binarySearch(arr, arrSize, num);
  // Prints iterative solution.
  // Should print: 2 is at index 4
  // printf("%d is at index %d.\n", num, index);
  
  // True case, number is in array
  assert(binarySearch(arr, arrSize, num) == 0);
  
  num = 5;
  // index = binarySearchRecursive(arr, num, 0, arrSize - 1);
  // Prints recursive solution.
  // Should print: 5 is at index -1
  // printf("%d is at index %d.\n", num, index);
  
  // False case, number is not found in the array
  assert(binarySearchRecursive(arr, num, 0, arrSize - 1) == 0);
}

// Pre-condition: takes in an array, size of the array, and number we want to find in the array.
// Post-condition: returns the index of the number.
int binarySearch(int *arr, int arrSize, int num) {
  int low = 0, high = arrSize - 1;
  
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == num) {
      return mid;
    }
    else if (arr[mid] < num) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  // indicates the number was not found
  return -1;
}


// Pre-condition: takes in an array, number we want to find in the array, start of array, and end of array.
// Post-condition: returns the index of the number.
int binarySearchRecursive(int *arr, int value, int low, int high) {
  // Initial check
  if (high < low) {
    return -1;
  }
  int mid = low + (high - low) / 2;
  
  if (arr[mid] == value) return mid;
  else if (arr[mid] < value) {
    return binarySearchRecursive(arr, value, mid + 1, high);
  }
  else {
    return binarySearchRecursive(arr, value, low, mid - 1);
  }
}

