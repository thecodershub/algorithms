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
  reorders the array arr to create a pivot that splits elements based on
  their value compared to the last element (the pivot) using the comparison
  function comp. lo and hi are internal helpers. Returns the index of the
  pivot.
*/
function partition(arr, comp, lo, hi) {
  const pivot = arr[hi];
  let i = lo;
  for (let j = lo; j < hi; j++) {
    if (comp(arr[j], pivot)) {
      swap(arr, i, j);
      i++;
    }
  }
  swap(arr, i, hi);
  return i;
}

/*
  Sorts (and mutates) arr. comp is the comparison function. It
  defaults to sorting numbers in ascending order. lo and hi are internal helpers.
*/
function quickSort(arr, comp = (a, b) => a < b, lo = 0, hi = arr.length - 1) {
  if (lo < hi) {
    const pivot = partition(arr, comp, lo, hi);
    quickSort(arr, comp, lo, pivot - 1);
    quickSort(arr, comp, pivot + 1, hi);
  }
}

// Usage:
const arr = [4, 5, 8, 2, 1, 0, 3];

// sort with default comparison
quickSort(arr);
console.log(arr);

// now reverse it
quickSort(arr, (a, b) => a > b);
console.log(arr);
