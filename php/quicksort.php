<?php

/**
 * Based on the haskell quicksort
 *
 * @param array $array
 *
 * @return array
 */
function quickSort(array $array) {

    // base case
    if (empty($array)) {
        return $array;
    }

    $head = array_shift($array);
    $tail = $array;

    $lesser = array_filter($tail, function ($item) use ($head) {
        return $item <= $head;
    });

    $bigger = array_filter($tail, function ($item) use ($head) {
        return $item > $head;
    });

    return array_merge(quickSort($lesser), [$head], quickSort($bigger));
}