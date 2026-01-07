package normal

func generateParenthesis(n int) []string {
	result := []string{}

	var gen func(s string, left, right int)

	gen = func(s string, left, right int) {
		if len(s) >= 2*n {
			result = append(result, s)
			return
		}

		if left < n {
			gen(s+"(", left+1, right)
		}

		if right < left {
			gen(s+")", left, right+1)
		}
	}

	return result
}
