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

mergeSort(arr); // [0, 1, 2, 3, 4, 5, 8]

// Tests:
// i => input, o => output, r => reversed output
const tests = [
  {
    i: [],
    o: [],
    r: []
  },
  {
    i: [ 0 ],
    o: [ 0 ],
    r: [ 0 ]
  },
  {
    i: [ 0, 0 ],
    o: [ 0, 0 ],
    r: [ 0, 0 ]
  },
  {
    i: [ 0, 0, 0 ],
    o: [ 0, 0, 0 ],
    r: [ 0, 0, 0 ]
  },
  {
    i: [ 0, 1 ],
    o: [ 0, 1 ],
    r: [ 1, 0 ]
  },
  {
    i: [ 1, 0 ],
    o: [ 0, 1 ],
    r: [ 1, 0 ]
  },
  {
    i: [ 0, 1, 2 ],
    o: [ 0, 1, 2 ],
    r: [ 2, 1, 0 ]
  },
  {
    i: [ 0, 2, 1 ],
    o: [ 0, 1, 2 ],
    r: [ 2, 1, 0 ]
  },
  {
    i: [ 1, 0, 2 ],
    o: [ 0, 1, 2 ],
    r: [ 2, 1, 0 ]
  },
  {
    i: [ 1, 2, 0 ],
    o: [ 0, 1, 2 ],
    r: [ 2, 1, 0 ]
  },
  {
    i: [ 2, 0, 1 ],
    o: [ 0, 1, 2 ],
    r: [ 2, 1, 0 ]
  },
  {
    i: [ 2, 1, 0 ],
    o: [ 0, 1, 2 ],
    r: [ 2, 1, 0 ]
  },
  {
    i: [ 0, 1, 1 ],
    o: [ 0, 1, 1 ],
    r: [ 1, 1, 0 ]
  },
  {
    i: [ 1, 0, 1 ],
    o: [ 0, 1, 1 ],
    r: [ 1, 1, 0 ]
  },
  {
    i: [ 1, 1, 0 ],
    o: [ 0, 1, 1 ],
    r: [ 1, 1, 0 ]
  },
  {
    i: [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ],
    o: [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ],
    r: [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]
  },
  {
    i: [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ],
    o: [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ],
    r: [ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 ]
  },
  {
    i: [ 42, 9, 17, 54, 602, -3, 54, 999, -11 ],
    o: [ -11, -3, 9, 17, 42, 54, 54, 602, 999 ],
    r: [ 999, 602, 54, 54, 42, 17, 9, -3, -11 ]
  },
  {
    i: [ -11, -3, 9, 17, 42, 54, 54, 602, 999 ],
    o: [ -11, -3, 9, 17, 42, 54, 54, 602, 999 ],
    r: [ 999, 602, 54, 54, 42, 17, 9, -3, -11 ]
  }
];

for (let j = 0; j < tests.length; j++) {

  console.assert(mergeSort(tests[j].i).toString() == tests[j].o.toString());
  console.assert(mergeSort(tests[j].i, (a, b) => a > b).toString == tests[j].r.toString);
}
