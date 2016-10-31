#include <stdio.h>
#include <stdlib.h>

/*
* Binary search function
* 
* searches for a value in sorted array
*   arr is an array to search in
*   value is searched value
*   left is an index of left boundary
*   right is an index of right boundary
* returns position of searched value, if it presents in the array
* or -1, if it is absent
*/
int binarySearch(int array[], int value, int left, int right) {
      while (left <= right){
            int middle = (left + right) / 2;
            if (array[middle] == value)
                  return middle;
            else if (array[middle] > value)
                  right = middle - 1;
            else
                  left = middle + 1;
      }
      return -1;
}

//Function to print an array
void printArray(int array[], int size){
 	for(int i = 0; i<size; i++){
 		if(i%10 == 0) printf("\n");
 		printf("%d\t", array[i]);
 	}
 	printf("\n");
 }

//Function to fill an array gradually
void fillArrayGradually(int array[], int size){
    for(int i = 0; i<size; i++){
        array[i] = i;
    }
}

//Function to fill an array randomly (but serialized) 
void fillArrayRandomly(int array[], int size){
    if(size > 0) array[0] = (rand() % 10) - 200; //starts with negative values
    for(int i = 1; i<size; i++){
        array[i] = array[i-1] + (rand() % 10);
    }
}

//Test of gradually filled array
void test1(){
    int array[100];
    fillArrayGradually(array,sizeof(array)/sizeof(int));
    printArray(array, sizeof(array)/sizeof(int));
    int value = rand()%100;
    printf("Value to find: %d\n", value);
    int position = binarySearch(array, value, 0, sizeof(array)/sizeof(int));
    if(position == -1) printf("Value not found\n");
    else printf("Value found on position: %d\n", position);
}

//Test of randomly filled array
void test2(){
    int array[100];
    fillArrayRandomly(array,sizeof(array)/sizeof(int));
 	printArray(array, sizeof(array)/sizeof(int));
    int value = rand()%100;
    printf("Value to find: %d\n", value);
    int position = binarySearch(array, value, 0, sizeof(array)/sizeof(int));
    if(position == -1) printf("Value not found\n");
    else printf("Value found on position: %d\n", position);
}

//Main function
int main(int argc, char *argv[]){
    test1();
    test2(); 
   
    return 0;
}
