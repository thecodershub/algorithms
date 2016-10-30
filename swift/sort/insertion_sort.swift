// Insertion sort implementation in Swift
// https://en.wikipedia.org/wiki/Insertion_sort


func insertionSort(inputArray: Array<Int>) -> Array<Int> {
    //Implementation of iterative insertion sort.
    var inputArray = inputArray;
    let n = inputArray.count;
    for i in 0..<n {
        var j = i;
        while (j > 0) && (inputArray[j-1] > inputArray[j]) {
            swap(&inputArray[j], &inputArray[j-1]);
            j -= 1;
        }
    }
    return inputArray;
}

func main() {
    let lis1 = [4, 1, 2, 3, 9];
    let lis2 = [1];
    let lis3 = [2, 2, 1, -1, 0, 4, 5, 2];
    let lis4 = [Int]();
    
    let sorted_lis1 = insertionSort(inputArray: lis1);
    assert(sorted_lis1 == [1, 2, 3, 4, 9]);
    
    let sorted_lis2 = insertionSort(inputArray: lis2);
    assert(sorted_lis2 == [1]);
    
    let sorted_lis3 = insertionSort(inputArray: lis3);
    assert(sorted_lis3 == [-1, 0, 1, 2, 2, 2, 4, 5]);
    
    let sorted_lis4 = insertionSort(inputArray: lis4);
    assert(sorted_lis4 == []);
}

main();