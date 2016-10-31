#import <iostream.h>
using namespaces std

void BubbleSort(int inArray[], int n)
{
	for( int i =0;i<n;i++)
	{
		for (int j =i+1;j<n;j++)
		{
			int temp = 0;
			if (inArray[i] > inArray[j])
			{
				temp = inArray[i];
				inArray[i]=inArray[j];
				inArray[j]=temp;
			}
		}
	}
}

int main()
{
	int* x = NULL;
    int n, numbers;
    cin >> n;
    x = new int[n];
    for (int i=0;i<n;i++)
    {
        cin >> numbers;
        x[i] = numbers;
    }

    BubbleSort(x,n)

    for (int j = 0; j < n; ++j)
    {
        cout << "x[" << j << "] = " << x[j] << endl;
    }

    return 0;
}