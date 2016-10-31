#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

void mergeSort(vector<int>& elements)
{
    int n = elements.size();
    vector<int> firstHalf(n/2), secondHalf(n - n/2);

    /*
     * Copy the two halves of the initial vector to a temporary storage.
     * This temporary location is where the recursive mergeSort call will
     * work on.
     */
    for(int i=0; i < firstHalf.size(); ++i)
    {
        firstHalf[i] = elements[i];
    }

    for(int i=0; i < secondHalf.size(); ++i)
    {
        secondHalf[i] = elements[n/2 + i];
    }

    if(elements.size() < 2)
        return;

    mergeSort(firstHalf);
    mergeSort(secondHalf);

    /* Merge */
    int p = 0;
    int q = 0;

    for(int i=0; i < n; ++i)
    {
        if(p < firstHalf.size())
	{
            if(q < secondHalf.size())
            {
                if(firstHalf[p] < secondHalf[q])
                {
                    elements[i] = firstHalf[p++];
                }
                else
                {
                    elements[i] = secondHalf[q++];
                }
            }
            else
            {
                elements[i] = firstHalf[p++];
            }
        }
        else
        {
            elements[i] = secondHalf[q++];
        }
    }

    return;
}

int checkMergeSort(vector<int>& elements)
{
    mergeSort(elements);
    for(int i = 1; i < elements.size(); ++i)
    {
        if(elements[i-1] > elements[i])
        {
            return 1;
        }
    }
    return 0;
}

int testMergeSort()
{
    vector<int> elements(100000);
    /* Test #1: All 0s */
    for(int i = 0; i < elements.size(); ++i)
    {
        elements[i] = 0;
    }
    assert(checkMergeSort(elements) == 0);

    /* Test #2: Range [0, NLIMIT) in increasing order */
    for(int i = 0; i < elements.size(); ++i)
    {
        elements[i] = i;
    }
    assert(checkMergeSort(elements) == 0);

    /* Test #3: Range [1, NLIMIT] in decreasing order */
    for(int i = 0, j = elements.size(); i < elements.size(); ++i)
    {
        elements[i] = j--;
    }
    assert(checkMergeSort(elements) == 0);

    return 0;
}

int main()
{
    testMergeSort();
    return 0;
}

