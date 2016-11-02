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
insertionSort(arr); // arr is now [0, 1, 2, 3, 4, 5, 8]

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
  insertionSort(input);
  console.assert(input.toString() === tests[j].o.toString());

  let input2 = tests[j].i.slice(0); // copy the array
  insertionSort(input2, (a, b) => a > b);
  console.assert(input2.toString() === tests[j].r.toString());
}
