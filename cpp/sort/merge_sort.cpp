/*
	Implementation of Merge Sort in C++(gcc 4.9.2)
	https://en.wikipedia.org/wiki/Merge_sort
*/

#include<iostream>
using namespace std;

int array[100000];

void merge(int l,int m,int r)
{
	int i,j,k,n1,n2;
	n1 = m-l+1;
	n2 = r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=array[l+i];
	for(j=0;j<n2;j++)
		R[j]=array[m+j+1];
	i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			array[k++]=L[i++];
		}
		else if(L[i]>R[j])
		{
			array[k++]=R[j++];
		}
		else
		{
			array[k++]=L[i++];
			array[k++]=R[i++];
		}
	}
	while(i<n1)
		array[k++]=L[i++];
	while(j<n2)
		array[k++]=R[j++];
}
void merge_sort(int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		merge_sort(l,m);
		merge_sort(m+1,r);
		merge(l,m,r);
	}
}

int main()
{
	int n,i;
	cout<<"Input length of array- ";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>array[i];
	merge_sort(0,n-1);
	cout<<"Sorted Array is-\n";
	for(i=0;i<n;i++)
		cout<<array[i]<<" ";
	return 0;
}