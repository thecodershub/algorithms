'use strict';

/*
  Returns the index of target within a sorted (ascending) int array, arr.
  If target is not found in the array, -1 is returned.
*/
function binarySearch(arr, target) {
  let lo = 0, hi = arr.length - 1;
  while (lo <= hi) {
    const mid = lo + Math.floor((hi - lo) / 2);
    if (arr[mid] === target) {
      return mid;
    } else if (arr[mid] < target) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  // target is not found
  return -1;
}

// Usage:
const arr = [2, 3, 9, 12, 30, 59, 100, 1024, 2866];

console.assert(binarySearch(arr, 2) == 0);
console.assert(binarySearch(arr, 3) == 1);
console.assert(binarySearch(arr, 9) == 2);
console.assert(binarySearch(arr, 12) == 3);
console.assert(binarySearch(arr, 30) == 4);
console.assert(binarySearch(arr, 59) == 5);
console.assert(binarySearch(arr, 100) == 6);
console.assert(binarySearch(arr, 1024) == 7);
console.assert(binarySearch(arr, 2866) == 8);
