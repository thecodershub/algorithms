func binarySearch<T:Comparable>(inputArr:Array<T>, searchItem: T)->Int{
    var lowerIndex = 0;
    var upperIndex = inputArr.count - 1

    while (true) {
        var currentIndex = (lowerIndex + upperIndex)/2
        if(inputArr[currentIndex] == searchItem) {
            return currentIndex
        } else if (lowerIndex > upperIndex) {
            return -1
        } else {
            if (inputArr[currentIndex] > searchItem) {
                upperIndex = currentIndex - 1
            } else {
                lowerIndex = currentIndex + 1
            }
        }
    }
}

var myArray = [1,2,3,4,5,6,7,9,10];
var searchIndex = binarySearch(myArray,5);
if searchIndex != -1{
    println("Element found on index: \(searchIndex)");
}
