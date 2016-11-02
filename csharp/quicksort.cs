using System;
using System.Diagnostics;
 
namespace Quicksort
{
    class Program
    {
        static void Main(string[] args)
        {
            TestSortedArray();
            TestTheWorstCaseArray();
            TestTwoUniqueNumbersInArray();
            TestRandomDataInArray();
            TestOnlyZeroNumbersInArray();
        }

        public static void QuicksortWraper(int[] elements)
        {
            Quicksort(elements, 0, elements.Length - 1);
        }
 
        public static void Quicksort(int[] elements, int left, int right)
        {
            int i = left;
            int j = right;
            int pivot = elements[(left + right) / 2];
 
            while (i <= j) {
                while (elements[i].CompareTo(pivot) < 0) {
                    i++;
                }
 
                while (elements[j].CompareTo(pivot) > 0) {
                    j--;
                }
 
                if (i <= j) {
                    int tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;
 
                    i++;
                    j--;
                }
            }
            if (left < j) {
                Quicksort(elements, left, j);
            }
 
            if (i < right) {
                Quicksort(elements, i, right);
            }
        }

        public static void TestSortedArray()
        {
            int[] toSort = { 10, 11, 12, 13, 14, 15, 16, 17, 18 };
            int[] toVerify = { 10, 11, 12, 13, 14, 15, 16, 17, 18 };

            QuicksortWraper(toSort);

            AssertEquals(toSort, toVerify);
        }


        public static void TestTheWorstCaseArray()
        {
            int[] toSort = { 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4 };
            int[] toVerify = { -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8 };

            QuicksortWraper(toSort);

            AssertEquals(toSort, toVerify);
        }

        public static void TestTwoUniqueNumbersInArray()
        {
            int[] toSort = { 1, 2, 1, 1, 2, 1, 2, 2 };
            int[] toVerify = { 1, 1, 1, 1, 2, 2, 2, 2 };

            QuicksortWraper(toSort);

            AssertEquals(toSort, toVerify);
        }

        public static void TestRandomDataInArray()
        {
            int[] toSort = { 800, 11, 50, 771, 649, 770, 240, 9 };
            int[] toVerify = { 9, 11, 50, 240, 649, 770, 771, 800 };

            QuicksortWraper(toSort);

            AssertEquals(toSort, toVerify);
        }

        public static void TestOnlyZeroNumbersInArray()
        {
            int[] toSort = { 0, 0, 0, 0, 0, 0, 0 };
            int[] toVerify = { 0, 0, 0, 0, 0, 0, 0 };

            QuicksortWraper(toSort);

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
}