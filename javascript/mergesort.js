'use strict'

/* 
  Returns a sorted array containing elements from left and right.
  comp is the comparison function for comparing the order of the
  elements in left and right. The resulting array will have length
  left.length + right.length.
  Requires:
    left and right to be sorted.
*/
function merge(left, right, comp) {
  let mergedArray = [];

  while(left.length && right.length) {
    if (comp(left[0], right[0])) {
      mergedArray.push(left.shift());
    } else {
      mergedArray.push(right.shift());
    }
  }

  if (left.length) mergedArray.push(...left);
  if (right.length) mergedArray.push(...right);

  return mergedArray;
}

/*
  Returns a sorted version of arr. comp is the comparison function. It
  defaults to sorting numbers in ascending order.
*/
function mergeSort(arr, comp = (a, b) => a < b) {
  if (arr.length <= 1) return arr;

  const left = arr.slice(0, arr.length / 2);
  const right = arr.slice(arr.length / 2, arr.length);

  return merge(mergeSort(left, comp), mergeSort(right, comp), comp);
}

// Usage:
const arr = [4, 5, 8, 2, 1, 0, 3];

console.log(mergeSort(arr));
console.log(mergeSort(arr, (a, b) => a > b));
