<?php

require_once __DIR__ . DIRECTORY_SEPARATOR . 'BinarySearch.php';

class TestBinarySearch {

    public function test() {
        $this->testBinarySearchSuccess();
        $this->testBinarySearchEmptyArray();
        $this->testBinarySearchNotFound();
    }

    public function testBinarySearchSuccess() {
        $array = [1, 2, 5, 10, 15, 20, 25, 28, 30, 55, 92, 102, 140];
        $idx = binary_search(25, $array);
        $this->assertEquals($idx, array_search(25, $array));
        $idx = binary_search(140, $array);
        $this->assertEquals($idx, array_search(140, $array));
    }

    public function testBinarySearchEmptyArray() {
        $array = [];
        $idx = binary_search(25, $array);
        $this->assertEquals($idx, -1);
    }

    public function testBinarySearchNotFound() {
        $array = [1, 2, 5, 10, 15, 20, 25, 28, 30, 55, 92, 102, 140];
        $idx = binary_search(29, $array);
        $this->assertEquals($idx, -1);
    }

    private function assertEquals($value, $matches) {
        if ($value === $matches) {
            echo "Success asserting that $value matches expected $matches." . PHP_EOL;
            return;
        }
        trigger_error("The value $value doesnt match the expected $matches.", E_USER_NOTICE);
    }
}

(new TestBinarySearch())->test();
