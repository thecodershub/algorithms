/**
 * Bubble sorts a list of numbers.
 * @param {Numer[]} listOfNums - Array of numbers to be sorted.
 * @return {Numer[]} listOfNums - Sorted array of initial parameter.
 */
function bubblesort(listOfNums) {
  for(var j = listOfNums.length; j > 0; j--) {
    for(var i = 1; i < j; i++) {
      if(listOfNums[i-1] > listOfNums[i]) {
        var holder = listOfNums[i-1];
        listOfNums[i-1] = listOfNums[i];
        listOfNums[i] = holder;
      }
    }
  }
  return listOfNums;
}
