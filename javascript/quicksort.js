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
quickSort(arr); // arr is now [0, 1, 2, 3, 4, 5, 8]

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
  let input = tests[j].i.slice(0); // copy the array
  quickSort(input);
  console.assert(input.toString() === tests[j].o.toString());

  let input2 = tests[j].i.slice(0); // copy the array
  quickSort(input2, (a, b) => a > b);
  console.assert(input2.toString() === tests[j].r.toString());
}

