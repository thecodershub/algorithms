/* 
	Implementation of Quick Sort in C++(4.9.2)
	https://en.wikipedia.org/wiki/Quicksort
*/

#include <iostream>
using namespace std;

int array[10000];

int partition(int l, int r)
{
	int i,j,pivot,temp;
	i=l-1;
	pivot = array[r];
	for(j=l;j<r;j++)
	{
		if(array[j]<=pivot)
		{	
			i++;
			temp = array[i];
			array[i]=array[j];
			array[j]=temp;
		}
	}
	temp = array[i+1];
	array[i+1]=array[r];
	array[r]=temp;
	return i+1;
}

void quick_sort(int l,int r)
{
	if(l<r)
	{
		int pivot_index = partition(l,r);
		quick_sort(l, pivot_index-1);
		quick_sort(pivot_index,r);
	}
}

int main()
{
	int n,i;
	cout<<"Input length of array- ";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>array[i];
	quick_sort(0,n-1);
	cout<<"Sorted Array is-\n";
	for(i=0;i<n;i++)
		cout<<array[i]<<" ";
	return 0;
}