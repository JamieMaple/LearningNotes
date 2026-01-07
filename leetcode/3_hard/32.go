package hard

func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestValidParenthesesStack(s string) int {
	maxLength := 0
	stack := []int{-1}

	for k, c := range s {
		if c == '(' {
			stack = append(stack, k)
			continue
		}

		stack = stack[:len(stack)-1]
		if len(stack) == 0 {
			stack = append(stack, k)
		} else {
			l := stack[len(stack)-1]
			maxLength = maxInt(maxLength, k-l)
		}
	}

	return maxLength
}

func longestValidParentheses(s string) int {
	maxLength := 0
	left := 0
	right := 0

	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			left++
		} else {
			right++
		}

		if left == right {
			maxLength = maxInt(maxLength, left+right)
		} else if right > left {
			left = 0
			right = 0
		}
	}

	left = 0
	right = 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '(' {
			left++
		} else {
			right++
		}

		if left == right {
			maxLength = maxInt(maxLength, left+right)
		} else if left > right {
			left = 0
			right = 0
		}
	}

	return maxLength
}
