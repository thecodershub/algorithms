#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h>
#include <time.h>

using namespace std;

void bubblesort(vector <int>& A)
{
	for(int i=0;i<A.size();i++)
		for(int j=i+1;j<A.size();j++)
			if(A[i] > A[j])
				swap(A[i], A[j]);

	return;
}

int check_sorted(vector <int>& A)
{
	for(int i=1;i<A.size();i++)
		if(A[i] < A[i-1])
			return 0;

	return 1;
}

void test_bubblesort()
{
	vector <int> A;

	for(int i=0;i<100;i++)
		A.push_back(rand());

	bubblesort(A);

	assert(check_sorted(A));
}

int main()
{
	srand (time(NULL));

	test_bubblesort();

	return 0;
}