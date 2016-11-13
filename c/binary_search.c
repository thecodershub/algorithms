#include <stdio.h>

// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l)/2;

		// If the element is present at the middle itself
		if (arr[mid] == x)  return mid;

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid+1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}

void test1()
{
	int arr[] = {2, 3, 4, 10, 40};
	printf("Test 1: \n");
	int n = sizeof(arr)/ sizeof(arr[0]);
	int x = 10;
	int result = binarySearch(arr, 0, n-1, x);
	(result == -1)? printf("Element is not present in array\n"):	printf("Element is present at index %d\n", result);
}

void test2()
{
	int arr[] = {1, 2 ,6, 12, 20000};
	printf("Test 2: \n");
	int n = sizeof(arr)/ sizeof(arr[0]);
	int x = 10;
	int result = binarySearch(arr, 0, n-1, x);
	(result == -1)? printf("Element is not present in array\n"):	printf("Element is present at index %d\n", result);
}

void test3()
{
	int arr[] = {1, 10 , 10, 120};		//Only first occurence is noted.
	printf("Test 3: \n");
	int n = sizeof(arr)/ sizeof(arr[0]);
	int x = 10;
	int result = binarySearch(arr, 0, n-1, x);
	(result == -1)? printf("Element is not present in array\n"):	printf("Element is present at index %d\n", result);
}

void test()
{
	test1();
	test2();
	test3();
}

int main(void)
{
	test();
	return 0;
}
