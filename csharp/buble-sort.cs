using System;
 
public class Test
{
	public static void Main()
	{
		int[] arr = { 800, 11, 50, 771, 649, 770, 240, 9 };
 
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
 
		for (int i = 0; i < arr.Length; i++)
		    Console.Write(arr[i] + " ");
	}
}
