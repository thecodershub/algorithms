#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int size){
	for(int i = 0; i < size - 1; i++){
	   for(int j = 0; j < size - i - 1; j++){
	       if(array[j+1] < array[j]){
		       int tmp = array[j + 1];
		       array[j + 1] = array[j];
		       array[j] = tmp;
	       }
	   }
	}
} 

void printArray(int array[], int size){
	for(int i = 0; i<size; i++){
		if(i%10 == 0) printf("\n");
		printf("%d\t", array[i]);
	}
	printf("\n");
}

void test1(){
	int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	bubbleSort(array, sizeof(array)/sizeof(int));
	printArray(array, sizeof(array)/sizeof(int));
}

void test2(){
	int array[10] = {0, -1, -2, -3, -4, -5, -6, -7, -8, -9};
	bubbleSort(array, sizeof(array)/sizeof(int));
	printArray(array, sizeof(array)/sizeof(int));
}

void test3(){
	int array[100];
	for(int i = 0; i<100; i++){
		array[i] = (rand() % 200) - 100; //values in range (-100; 99)
	}
	bubbleSort(array, sizeof(array)/sizeof(int));
	printArray(array, sizeof(array)/sizeof(int));
}

int main(){
	test1();
	test2();
	test3();

	return 0;
}
