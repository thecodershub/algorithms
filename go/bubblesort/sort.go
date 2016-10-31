package bubblesort

func sort(s []int) {
	for {
		swapped := false

		for i := 0; i < len(s)-1; i++ {
			if s[i] > s[i+1] {
				s[i], s[i+1] = s[i+1], s[i]
				swapped = true
			}
		}

		if !swapped {
			break
		}
	}
}
