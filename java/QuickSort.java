class QuickSort {
    public static void quickSort(int[] theArray, int left, int right) {
        //we declare 2 variables
        int i = left;
        int j = right;

        //we calculate a pivot, simply taking the middle value of the array
        int pivot = theArray[(left + right) / 2];

        //check that i hasn't gone beyond j (i starts at 0, j starts at array.length)
        while (i <= j) {
            //if here, must mean i is less-than or equal to j, so check to see if
            //the array value i is less than our pivot
            while (theArray[i] < pivot) {
                //if it is less-than pivot, the value theArray[i] is in correct place
                //so we can increment i to go to next
                i++;
            }
            //now do exactly same thing for j, however, j starts at array.length, so decrement
            while (theArray[j] > pivot) {
                j--;
            }
            //if we are here, it likely means we need to swap values
            //check that i hasn't gone beyond j
            int temp;
            if (i <= j) {
                //simple swap
                temp = theArray[i];
                theArray[i] = theArray[j];
                theArray[j] = temp;
                //we just swapped values, so we don't need to check them again, so continue
                i++;
                j--;
            }
        }
        //now check if parameter left is < j
        //if left has gone beyond j, it means we no longer need to further sort
        if (left < j) {
            //rinse and repeat
            quickSort(theArray, left, j);
            //and check that i is still less than right parameter
        }
        if (i < right) {
            //rinse and repeat
            quickSort(theArray, i, right);
        }

    }

    // print the array to console.
    private static void print(int[] arr) {
        for (int i : arr)
            System.out.print(i + " ");
            
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        //you can amend this code so you don't have to pass in an array
        int theArray[] = {10, 5, 13, 8, 7, 89, 12, 13};
        print(theArray);
        quickSort(theArray, 0, theArray.length - 1);
        print(theArray);
    }
}
