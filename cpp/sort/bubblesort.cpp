#include <stdio.h>
#include <stdlib.h>

//Bubble sort function
void bubbleSort(int *array, int size){
    for(int i = 0; i<size-1; i++){
        for(int j = 0; j<size-i-1; j++){
			if(array[j+1] < array[j]){
            //swap without using third variable
				array[j] += array[j+1];
				array[j+1] = array[j] - array[j+1];
				array[j] = array[j] - array[j+1];
			}
		}
	}
}

//Function to print an array
void printArray(int *array, int size){
	for(int i = 0; i<size; i++){
		if(i%10 == 0) printf("\n");
		printf("%d\t", array[i]);
	}
	printf("\n");
}

//Test of positive values
void test1(){
	int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	printf("Test 1\n");
	printf("Array: \n");
	printArray(array, sizeof(array)/sizeof(int));
	bubbleSort(array, sizeof(array)/sizeof(int));
	printf("Sorted Array: \n");
	printArray(array, sizeof(array)/sizeof(int));
    printf("\n\n\n");
}

//Test of negative values
void test2(){
	int array[10] = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0};
	printf("Test 2\n");
	printf("Array: \n");
	printArray(array, sizeof(array)/sizeof(int));
	bubbleSort(array, sizeof(array)/sizeof(int));
	printf("Sorted Array: \n");
	printArray(array, sizeof(array)/sizeof(int));
    printf("\n\n\n");
}

//Test of random 1000 values
void test3(){
    int array[1000];
	for(int i = 0; i<1000; i++){
        array[i] = (rand() % 200) - 100; //random values in range (-100; 99)
    }
	printf("Test 2\n");
	printf("Array: \n");
	printArray(array, sizeof(array)/sizeof(int));
	bubbleSort(array, sizeof(array)/sizeof(int));
	printf("Sorted Array: \n");
	printArray(array, sizeof(array)/sizeof(int));
    printf("\n\n\n");
}

//Main function
int main(int argc, char*argv[]){
	test1();
    test2();
    test3();

    return 0;
}

