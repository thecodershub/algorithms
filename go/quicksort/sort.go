package quicksort

func sort(s []int) {

	if len(s) == 0 {
		return
	}

	pivot := s[0]
	rest := s[1:]

	firstLarger := 0
	for i, v := range rest {
		if v <= pivot {
			rest[firstLarger], rest[i] = rest[i], rest[firstLarger]
			firstLarger++
		}
	}

	// here firstLarger actually points to the last less-than-or-equal element
	// because it is named after its meaning in the slice rest
	pivotPosition := firstLarger

	s[0] = s[pivotPosition]
	s[pivotPosition] = pivot

	sort(s[:pivotPosition])
	sort(s[pivotPosition+1:])
}