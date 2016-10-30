/*
* C++ Program to Implement Merge Sort
*/
#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,high,mid);
	}
	return;
}
void merge(int *a, int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		a[i] = c[i];
	}
}

void test1()
{
	int a[] = {1, 2, 56, 2, -564, 23};

	int i;
	int n = sizeof(a)/sizeof(a[0]);

	printf("Test 1: \n");

	cout<<"Unsorted array\n";
	for (i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	mergesort(a, 0, n-1);
	cout<<"\nSorted array\n";
	for (i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	printf("\n\n");
}

void test2()
{
	int a[] = {1};

	int i;
	int n = sizeof(a)/sizeof(a[0]);
	
	printf("Test 2: \n");

	cout<<"Unsorted array\n";
	for (i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	mergesort(a, 0, n-1);
	cout<<"\nSorted array\n";
	for (i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	printf("\n\n");
}

void test3()
{
	int a[] = {-4, -232, -4, 0, 1000};

	int i;
	int n = sizeof(a)/sizeof(a[0]);
	
	printf("Test 3: \n");

	cout<<"Unsorted array\n";
	for (i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	mergesort(a, 0, n-1);
	cout<<"\nSorted array\n";
	for (i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	printf("\n\n");
}

void test()
{
	test1();
	test2();
	test3();
}

int main()
{
	test();
	return 0;
}
