package main

import (
	"fmt"
)

//SOURCE:https://play.golang.org/p/Ma2GXvj3XP
func main() {
	s := []int{7, 5, 2, 1, 4, 9, 3, 6, 8}
	fmt.Printf("Before sort:%v\nAfter sort:%v\n", s, MergeSort(s))
}

func MergeSort(toSort []int) []int {
	if len(toSort) <= 1 {
		return toSort
	}
	//the mid
	mid := len(toSort) / 2
	//left side
	left := MergeSort(toSort[:mid])
	//right side
	right := MergeSort(toSort[mid:])
	return Merge(left, right)
}

func Merge(left []int, right []int) []int {
	lst := make([]int, 0, len(left)+len(right))
	for len(left) > 0 || len(right) > 0 {
		if len(left) == 0 {
			return append(lst, right...)
		}
		if len(right) == 0 {
			return append(lst, left...)
		}
		if left[0] <= right[0] {
			lst = append(lst, left[0])
			left = left[1:]
		} else {
			lst = append(lst, right[0])
			right = right[1:]
		}
	}
	return lst
}
