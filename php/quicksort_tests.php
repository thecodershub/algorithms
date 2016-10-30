<?php
require __DIR__ . DIRECTORY_SEPARATOR . 'quicksort.php';

function imp($arr) {
    return implode(', ', $arr);
}

function showResult($testCase, $array) {
    echo sprintf("[%s] ==> [%s]\n", imp($testCase), imp($array));
}

// Test empty array
$testCase = [];
$baseCase = quickSort($testCase);
if (!empty($baseCase)) {
    trigger_error('Result should be empty', E_USER_NOTICE);
}
showResult($testCase, $baseCase);

// Test 1 item array
$testCase = [1];
$oneItemCase = quickSort($testCase);
if ($oneItemCase !== [1]) {
    trigger_error('Result should be [1]', E_USER_NOTICE);
}
showResult($testCase, $oneItemCase);

// Test 2 items array
$testCase = [3, 1];
$twoItemsCase = quickSort($testCase);
if ($twoItemsCase !== [1, 3]) {
    trigger_error('Result should be [1, 3]', E_USER_NOTICE);
}
showResult($testCase, $twoItemsCase);

// Test with several items
$testCase = [1, 4, 8, 2, 8, 0, 2, 8];
$severalItems = quickSort($testCase);
if ($severalItems !== [0, 1, 2, 2, 4, 8, 8, 8]) {
    trigger_error('Result should be [0, 1, 2, 2, 4, 8, 8, 8]', E_USER_NOTICE);
}
showResult($testCase, $severalItems);

// Negative case
$testCase = [2, 3, 1, 4];
$negativeItemsCase = quickSort($testCase);
if ($negativeItemsCase === [4, 3, 2, 1]) {
    trigger_error('Result should NOT be [4, 3, 2, 1]', E_USER_NOTICE);
}
showResult($testCase, $negativeItemsCase);