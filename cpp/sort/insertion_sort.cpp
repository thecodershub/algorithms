/*
	Implementation of Insertion Sort in c++(gcc 4.9.2)
	https://en.wikipedia.org/wiki/Insertion_sort
*/

#include <iostream>
using namespace std;
int array[10000];

void insertion_sort(int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=array[i];
		j=i-1;
		while(j>=0 && key<array[j])
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;
	}
}

int main()
{
	int n,i;
	cout<<"Input length of array- ";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>array[i];
	insertion_sort(n);
	cout<<"Sorted Array is-\n";
	for(i=0;i<n;i++)
		cout<<array[i]<<" ";
	return 0;
}