/**
 * Bubble sorts a list of numbers.
 * @param {Numer[]} listOfNums - Array of numbers to be sorted.
 * @return {Numer[]} listOfNums - Sorted array of initial parameter.
 */
function bubblesort(listOfNums) {
  for(var j = 0; j < listOfNums.length - 1; j++) {
    for(var i = j + 1; i < listOfNums.length; i++) {
      if(listOfNums[i] < listOfNums[j]) {
        var holder = listOfNums[j];
        listOfNums[j] = listOfNums[i];
        listOfNums[i] = holder;
      }
    }
  }
  return listOfNums;
}
