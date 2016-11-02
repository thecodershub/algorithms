using System;
using System.Diagnostics;


public class Test
{
	public static void Main()
	{
		TestSortedArray();
        TestTheWorstCaseArray();
        TestTwoUniqueNumbersInArray();
        TestRandomDataInArray();
        TestOnlyZeroNumbersInArray();
	}

    public static void BubleSort(int[] arr)
    {
        int temp = 0;
 
        for (int write = 0; write < arr.Length; write++) {
            for (int sort = 0; sort < arr.Length - 1; sort++) {
                if (arr[sort] > arr[sort + 1]) {
                    temp = arr[sort + 1];
                    arr[sort + 1] = arr[sort];
                    arr[sort] = temp;
                }
            }
        }
    }


    public static void TestSortedArray()
    {
        int[] toSort = { 10, 11, 12, 13, 14, 15, 16, 17, 18 };
        int[] toVerify = { 10, 11, 12, 13, 14, 15, 16, 17, 18 };

        BubleSort(toSort);

        AssertEquals(toSort, toVerify);
    }


    public static void TestTheWorstCaseArray()
    {
        int[] toSort = { 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4 };
        int[] toVerify = { -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8 };

        BubleSort(toSort);

        AssertEquals(toSort, toVerify);
    }

    public static void TestTwoUniqueNumbersInArray()
    {
        int[] toSort = { 1, 2, 1, 1, 2, 1, 2, 2 };
        int[] toVerify = { 1, 1, 1, 1, 2, 2, 2, 2 };

        BubleSort(toSort);

        AssertEquals(toSort, toVerify);
    }

    public static void TestRandomDataInArray()
    {
        int[] toSort = { 800, 11, 50, 771, 649, 770, 240, 9 };
        int[] toVerify = { 9, 11, 50, 240, 649, 770, 771, 800 };

        BubleSort(toSort);

        AssertEquals(toSort, toVerify);
    }

    public static void TestOnlyZeroNumbersInArray()
    {
        int[] toSort = { 0, 0, 0, 0, 0, 0, 0 };
        int[] toVerify = { 0, 0, 0, 0, 0, 0, 0 };

        BubleSort(toSort);

        AssertEquals(toSort, toVerify);
    }

    public static void AssertEquals(int[] a, int[] b)
    {
        Debug.Assert(a.Length == b.Length, "Length of arrays are not equals.");

        for (int i = 0; i < a.Length; i++) {
            Debug.Assert(a[i] == b[i], "Cells of arrays are not equals.");            
        }
    }

}
