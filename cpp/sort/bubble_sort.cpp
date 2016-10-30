/* 
Implementation of Bubble Sort in C++ (gcc 4.9.2)
https://en.wikipedia.org/wiki/Bubble_sort
*/

#include <iostream>
using namespace std;

int array[100000];

void bubble_sort(int n)
{
	int temp,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
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
	bubble_sort(n);
	cout<<"Sorted Array is-\n";
	for(i=0;i<n;i++)
		cout<<array[i]<<" ";
	return 0;
}