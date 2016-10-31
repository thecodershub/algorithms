#include<iostream>

using namespace std;

int main()
{
	int n;

	cout<<"Enter number of elements to be sorted"<<endl;

	cin>>n;

	int arr[n];

	cout<<"Enter the numbers"<<endl;

	for(int i=0;i<n;i++)
		cin>>arr[i];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	cout<<"The sorted numbers are : "<<endl;

	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
}