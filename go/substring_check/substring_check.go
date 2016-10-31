package main

/*
* The simple substring check
 */
func SubstringCheck(str, pattern string) bool {
	len_p := len(pattern)
	len_s := len(str)

	if len_p > len_s {
		return false
	}

	contain := true
	for i := 0; i < len_s-len_p; i++ {
		for j := i; j < i+len_p; j++ {
			contain = true
			if str[j] != pattern[j-i] {
				contain = false
				break
			}
		}
		if contain {
			return true
		}
	}
	return false
}
