using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
 
namespace Quicksort
{
    class Program
    {
        static void Main(string[] args)
        {
            // Create an unsorted array of string elements
            int[] unsorted = { 34, -2, 43, 1, 56, 7, 89, 102, 3};
 
            // Print the unsorted array
            for (int i = 0; i < unsorted.Length; i++)
            {
                Console.Write(unsorted[i] + " ");
            }
 
            Console.WriteLine();
 
            // Sort the array
            Quicksort(unsorted, 0, unsorted.Length - 1);
 
            // Print the sorted array
            for (int i = 0; i < unsorted.Length; i++)
            {
                Console.Write(unsorted[i] + " ");
            }
 
            Console.WriteLine();
 
            Console.ReadLine();
        }
 
        public static void Quicksort(int[] elements, int left, int right)
        {
            int i = left, j = right;
            int pivot = elements[(left + right) / 2];
 
            while (i <= j)
            {
                while (elements[i].CompareTo(pivot) < 0)
                {
                    i++;
                }
 
                while (elements[j].CompareTo(pivot) > 0)
                {
                    j--;
                }
 
                if (i <= j)
                {
                    // Swap
                    int tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;
 
                    i++;
                    j--;
                }
            }
 
            // Recursive calls
            if (left < j)
            {
                Quicksort(elements, left, j);
            }
 
            if (i < right)
            {
                Quicksort(elements, i, right);
            }
        }
 
    }
}