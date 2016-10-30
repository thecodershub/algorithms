#include <string.h>
#define NLIMIT 100000

void mergeSort(int arr[], int n)
{
    int tmp[NLIMIT];
    int *firstHalf = tmp;
    int *secondHalf = tmp + n/2;
    int firstHalfSize = n/2;
    int secondHalfSize = (n - n/2);
    int i, p, q;

    if(n < 2)
        return;

    /*
     * Copy the two halves of the initial array to a temporary storage.
     * This temporary location is where the recursive mergeSort call will
     * work on.
     */
    memcpy(firstHalf, arr, n/2 * sizeof(int));
    memcpy(secondHalf, arr + n/2, (n - n/2) * sizeof(int));

    mergeSort(firstHalf, n/2);
    mergeSort(secondHalf, n - n/2);

    /* Merge */
    i = 0;
    p = 0;
    q = 0;
    while(i < n)
    {
        if(p < firstHalfSize)
	{
            if(q < secondHalfSize)
            {
                if(firstHalf[p] < secondHalf[q])
                {
                    arr[i++] = firstHalf[p++];
                }
                else
                {
                    arr[i++] = secondHalf[q++];
                }
            }
            else
            {
                arr[i++] = firstHalf[p++];
            }
        }
        else
        {
            arr[i++] = secondHalf[q++];
        }
    }

    return;
}

int checkMergeSort(int arr[], int n)
{
    int i;
    mergeSort(arr, n);
    for(i = 1; i < n; ++i)
    {
        if(arr[i-1] > arr[i])
        {
            return 1;
        }
    }
    return 0;
}

int testMergeSort()
{
    int i, j, arr[NLIMIT];
    /* Test #1: All 0s */

    for(i = 0; i < NLIMIT; ++i)
    {
        arr[i] = 0;
    }
    if(checkMergeSort(arr, NLIMIT))
    {
        return 1;
    }

    /* Test #2: Range [0, NLIMIT) in increasing order */

    for(i = 0; i < NLIMIT; ++i)
    {
        arr[i] = i;
    }
    if(checkMergeSort(arr, NLIMIT))
    {
        return 1;
    }

    /* Test #3: Range [1, NLIMIT] in decreasing order */
    j = NLIMIT;
    for(i = 0; i < NLIMIT; ++i)
    {
        arr[i] = j--;
    }
    if(checkMergeSort(arr, NLIMIT))
    {
        return 1;
    }

    return 0;
}

int main()
{
    testMergeSort();
    return 0;
}

