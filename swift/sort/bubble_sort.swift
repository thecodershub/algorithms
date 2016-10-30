// Bubble sort implementation in Swift
// https://en.wikipedia.org/wiki/Bubble_sort


func bubbleSort(inputArray: Array<Int>) -> Array<Int> {
    // implementation of Bubble Sort 
    var inputArray = inputArray;
    var n = inputArray.count;
    while n > 0 {
        var temp_n = 0;
        for i in 1..<n {
            if inputArray[i-1] > inputArray[i] {
                swap(&inputArray[i], &inputArray[i-1]);
                temp_n = i;
            }
        }
        n = temp_n;
    }
    return inputArray;
}

func main() {
    let lis1 = [4, 1, 2, 3, 9];
    let lis2 = [1];
    let lis3 = [2, 2, 1, -1, 0, 4, 5, 2];
    let lis4 = [Int]();
    
    let sorted_lis1 = bubbleSort(inputArray: lis1);
    assert(sorted_lis1 == [1, 2, 3, 4, 9]);
    
    let sorted_lis2 = bubbleSort(inputArray: lis2);
    assert(sorted_lis2 == [1]);
    
    let sorted_lis3 = bubbleSort(inputArray: lis3);
    assert(sorted_lis3 == [-1, 0, 1, 2, 2, 2, 4, 5]);
    
    let sorted_lis4 = bubbleSort(inputArray: lis4);
    assert(sorted_lis4 == []);
}

main();