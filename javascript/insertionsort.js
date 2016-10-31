'use strict'

/*
  Swaps values at indices i and j of array arr.
  Mutates arr.
*/
function swap(arr, i, j) {
  const tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

/*
  Sorts (and mutates) arr. comp is the comparison function. It
  defaults to sorting numbers in ascending order.
*/
function insertionSort(arr, comp = (a, b) => a < b) {
  for (let i = 1; i < arr.length; i++) {
    let j = i;
    while (j > 0 && comp(arr[j], arr[j - 1])) {
      swap(arr, j, j - 1);
      j = j - 1;
    }
  }
}

// Usage:
const arr = [4, 5, 8, 2, 1, 0, 3];

// sort with default comparison
insertionSort(arr);
console.log(arr);

// now reverse it
insertionSort(arr, (a, b) => a > b);
console.log(arr);
