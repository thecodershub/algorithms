package com.thecodershub.algorithms;

import java.util.Random;

public class insertion_sort{
	
	// data fields
	private int arrLength;
	private Integer[] arr;
	
	// default constructor
	public insertion_sort() {
		arrLength = 10;
		arr = new Integer[arrLength];

		for (int i = 0; i < arrLength; i++) {
			arr[i] = 0;
		}
	}

	public void insertionSort() {
		int temp = 0;
		for (int i = 1; i < arrLength; i++) {
			// sorted part
			for (int j = i; j > 0; j--) {
				if (arr[j] < arr[j-1]) {
					temp = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = temp;

				}
			}
		}

	}// insertion sort method
	
	public void generateNumbers() {
		Random randy = new Random();

		for (int i = 0; i < arrLength; i++) {
			arr[i] = randy.nextInt(100) + 1;
		}

	}// end of generateNumbers
	
	public String toString() {

		StringBuilder builder = new StringBuilder();

		for (int i = 0; i < arrLength; i++) {

			builder.append(arr[i] + " ");
		}

		return builder.toString();

	}// end of toString
	
	//launcher
	public static void main(String[] args){
		
		insertion_sort ssort = new insertion_sort();
		
		ssort.generateNumbers();
		
		System.out.println("The numbers before sort are:");
		System.out.println(ssort.toString());
		System.out.println("\n");
		
		
		ssort.insertionSort();
		
		System.out.println("The numbers after sort are:");
		System.out.println(ssort.toString());
	
	}
}
