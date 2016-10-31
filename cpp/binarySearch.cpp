/*This code is made by Shubham Khanna*/
#include<iostream>
using namespace std;
int binarySearch(int a[],int size, int num)
{
	int first=0,last=s-1,found= 0;
	int mid
	while(first<=last)
	{
		mid = (first+last)/2; 					// Obtain the middle element of the array
		if(a[mid]==n)
		{
			cout<<"Number found! Position: "<<mid+1<<endl;
			found=1;
			break;
		}
		else if(a[mid]<num)
		{
			first=mid+1;
		}
		else
		{
			last=mid-1;
		}
	}
	if(found==0)
	{
		cout<<"Number not found!\n";
	}
	return 0;
}
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10},size=10,num;   // It is assumed that the array is completely sorted in ascending order
	cout<<"Enter number to search: ";
	cin>>num;
	binarySearch(a,size,num);
	return 0;
}