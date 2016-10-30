public class MergeSort {
    public static void main(String[] args) {
        int[] arr = {5, 4, 7, 2, 3, 1, 6, 2};

        print(arr);
        new MergeSort().sort(arr, 0, arr.length - 1);
    }

    private void sort(int[] arr, int lo, int hi) {
        if (lo < hi) {
            int mid = (lo + hi) / 2;
            sort(arr, lo, mid);           // recursive call to divide the sub-list
            sort(arr, mid + 1, hi);       // recursive call to divide the sub-list
            merge(arr, lo, mid, hi);      // merge the sorted sub-lists.
            print(arr);
        }
    }

    private void merge(int[] arr, int lo, int mid, int hi) {
        // allocate enough space so that the extra 'sentinel' value
        // can be added. Each of the 'left' and 'right' sub-lists are pre-sorted.
        // This function only merges them into a sorted list.
        int[] left = new int[(mid - lo) + 2];        
        int[] right = new int[hi - mid + 1];         


        // create the left and right sub-list for merging into original list.
        System.arraycopy(arr, lo, left, 0, left.length - 1);
        System.arraycopy(arr, mid + 1, right, 0, left.length - 1);

        // giving a sentinal value to marking the end of the sub-list.
        // Note: The list to be sorted is assumed to contain numbers less than 100.
        left[left.length - 1] = 100;
        right[right.length - 1] = 100;

        int i = 0;
        int j = 0;

        // loop to merge the sorted sequence from the 2 sub-lists(left and right) 
        // into the main list.
        for (; lo <= hi; lo++) {
            if (left[i] <= right[j]) {
                arr[lo] = left[i];
                i++;
            } else {
                arr[lo] = right[j];
                j++;
            }
        }
    }

    // print the array to console.
    private static void print(int[] arr) {
        System.out.println();
        for (int i : arr) {
            System.out.print(i + ", ");
        }
    }
}
