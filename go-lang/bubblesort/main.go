package main

import (
	"fmt"
)

func main() {
	s := []int{7, 5, 2, 1, 4, 9, 3, 6, 8}
	fmt.Printf("Before swap:%v\n", s)
	Swap(s, 0, 2)
	fmt.Printf("After swap:%v\n", s)
	fmt.Printf("Before bubble sort:%v\n", s)
	fmt.Printf("After bubble sort:%v\n", BubbleSort(s))

}

func BubbleSort(s []int) []int {
	sort := make([]int, len(s))
	copy(sort, s)
	if len(sort) == 1 {
		return sort
	}
	swapped := true
	for swapped {
		swapped = false
		for i := 0; i < len(sort)-1; i++ {
			if sort[i+1] < sort[i] {
				Swap(sort, i+1, i)
				swapped = true
			}
		}
	}
	return sort
}
func Swap(s []int, s1 int, s2 int) {
	temp := s[s1]
	s[s1] = s[s2]
	s[s2] = temp
}
