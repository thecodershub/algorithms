<?php

function selection_sort($array) {

    for ($i = 0, $size = count($array); $i < $size; $i++) {

        // define the first index as smallest
        $smallest = $i;

        // search for another index with small value previously marked as smallest
        for ($j = $i + 1; $j < $size; $j++) {
            if ($array[$j] < $array[$smallest]) {
                $smallest = $j;
            }
        }

        // check if the index defined at beginning changed and swap if true
        if ($smallest != $i) {
            $aux = $array[$i];
            $array[$i] = $array[$smallest];
            $array[$smallest] = $aux;
        }
    }

    return $array;
}


