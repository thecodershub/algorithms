/*
	Implementation of Selection Sort in c++(gcc 4.9.2)
	https://en.wikipedia.org/wiki/Selection_sort
*/

#include <iostream>
using namespace std;

int array[10000];

void selection_sort(int n)
{
	int i,j,temp,minpos;
	for(i=0;i<n;i++)
	{
		minpos=i;
		for(j=i;j<n;j++)
		{
			if(array[j]<array[minpos])
			{
				minpos=j;
			}
		}
		if(minpos!=i)
		{
			temp=array[minpos];
			array[minpos]=array[i];
			array[i]=temp;
		}
	}
}

int main()
{
	int n,i;
	cout<<"Input length of array- ";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>array[i];
	selection_sort(n);
	cout<<"Sorted Array is-\n";
	for(i=0;i<n;i++)
		cout<<array[i]<<" ";
	return 0;
}