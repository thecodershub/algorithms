<?php

function binary_search($needle, $array) {

    $left = 0;
    $right = count($array) - 1;

    while ($left <= $right) {
        $mid = ($left + $right) >> 1;

        if ($array[$mid] == $needle) {
            return $mid;
        } else if ($array[$mid] > $needle) {
            $right = $mid - 1;
        } else if ($array[$mid] < $needle) {
            $left = $mid + 1;
        }
    } while ($left <= $right);

    return -1;
}