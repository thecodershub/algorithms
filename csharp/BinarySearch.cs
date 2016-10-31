using System;
 
namespace BinarySearch
{
    class Program
    {
        static void Main(string[] args)
        {
            TestBinarySearch();
        }
        
        private static void TestBinarySearch() {
            int[] a = new int[] { 2, 4, 6, 8, 9 };
            Console.WriteLine(BinarySearchIterative(a, 9));
            Console.WriteLine(BinarySearchRecursive(a, 9, 0, a.Length));
        }
 
        private static int BinarySearchIterative(int[] arr, int val){
            int low = 0;
            int high = arr.Length;
            // Based on if our guess was higher or lower, 
            // we select a midpoint on the upper half or lower half
            // of the range and guess again. 
            while (low <= high)
            {
                // Start with the range's midpoint as our guess
                int mid = (low + high) / 2;
                if (arr[mid] > val)
                    high = mid-1;
                else if (arr[mid] < val)
                    low = mid+1;
                else
                    return mid;
            }
            return -1;
        }
 
        private static int BinarySearchRecursive(int[] arr, int val, int low, int high)
        {
            if (high < low)
                return -1;
            int mid = (low + high) / 2;
            if (a[mid] > val)
                return BinarySearchRecursive(arr, val, low, mid - 1);
            else if (arr[mid] < val)
                return BinarySearchRecursive(arr, val, mid + 1, high);
            else
                return mid;
        }
    }
}
