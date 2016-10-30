#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& elements, int p, int r)
{
    if(r - p < 1)
        return;

    /*
     * Though there are other strategies for picking a pivot,
     * the first element of the vector is picked as pivot for
     * demonstration purposes.
     */
    int pivot = elements[p], pivotIndex = p;

    for(int i = (p + 1); i <= r; ++i)
    {
        if(elements[i] < pivot)
        {
            elements[pivotIndex] = elements[i];
            elements[i] = elements[++pivotIndex];
        }
    }
    elements[pivotIndex] = pivot;

    quickSort(elements, p, pivotIndex-1);
    quickSort(elements, pivotIndex+1, r);
}

int checkQuickSort(vector<int>& elements)
{
    quickSort(elements, 0, elements.size() - 1);
    for(int i = 1; i < elements.size(); ++i)
    {
        if(elements[i-1] > elements[i])
        {
            return 1;
        }
    }
    return 0;
}

int testQuickSort()
{
    vector<int> elements(10);
    /* Test #1: All 0s */
    for(int i = 0; i < elements.size(); ++i)
    {
        elements[i] = 0;
    }
    if(checkQuickSort(elements))
    {
        return 1;
    }

    /* Test #2: Range [0, NLIMIT) in increasing order */
    for(int i = 0; i < elements.size(); ++i)
    {
        elements[i] = i;
    }
    if(checkQuickSort(elements))
    {
        return 1;
    }

    /* Test #3: Range [1, NLIMIT] in decreasing order */
    for(int i = 0, j = elements.size(); i < elements.size(); ++i)
    {
        elements[i] = j--;
    }
    if(checkQuickSort(elements))
    {
        return 1;
    }

    return 0;
}

int main()
{
    testQuickSort();
    return 0;
}
