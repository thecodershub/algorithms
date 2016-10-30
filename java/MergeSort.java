import java.util.Arrays;

public class MergeSort {

  public static int[] sort(int[] arr) {
    int[] copy = Arrays.copyOf(arr, arr.length);

    return mergeSort(copy, 0, copy.length-1);
  }

  public static void main(String[] args) {
    int[] input = {22,1,6,40,32,10,18,4,50};

    // Ttest MergeSort
    System.out.println("MergeSort: " + Arrays.toString(sort(input)));
  }

  private static int[] mergeSort(int[] arr, int lower, int higher) {
    int[] copy = Arrays.copyOfRange(arr, lower, higher+1);
    higher -= copy.length;

    if(copy.length == 1)
      return copy;
    else if(copy.length == 2) {
      if(copy[0] > copy[1])
        swap(copy, 0, 1);
      return copy;
    }

    return merge(mergeSort(copy, 0, higher/2), mergeSort(copy, higher/2+1, copy.length-1));
  }

  private static int[] merge(int[] arr1, int[] arr2) {
    int[] mergedArr = new int[arr1.length + arr2.length];

    int arr1Index = 0, arr2Index = 0;
    for(int i=0; i<mergedArr.length; i++) {
      if(arr1Index < arr1.length && arr2Index < arr2.length) {
        if(arr1[arr1Index] < arr2[arr2Index]) {
          mergedArr[i] = arr1[arr1Index];
          arr1Index++;
        } else {
          mergedArr[i] = arr2[arr2Index];
          arr2Index++;
        }
      } else if(arr1Index < arr1.length) {
        mergedArr[i] = arr1[arr1Index];
        arr1Index++;
      } else {
        mergedArr[i] = arr2[arr2Index];
        arr2Index++;
      }
    }

    return mergedArr;
  }

  private static void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
