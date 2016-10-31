package bubblesort

import "testing"

func withInput(t *testing.T, input []int) {
	sort(input)

	for i := 1; i < len(input); i++ {
		if input[i-1] > input[i] {
			t.Fatalf("Got %v instead of nondecreasing slice.", input)
		}
	}
}

func TestEmpty(t *testing.T) {
	withInput(t, []int{})
}

func TestOne(t *testing.T) {
	withInput(t, []int{1})
}

func TestFiveNumbers(t *testing.T) {
	withInput(t, []int{8, 2, 3, 8, -1})
}

func TestSorted(t *testing.T) {
	withInput(t, []int{3, 4, 5, 6, 8})
}
