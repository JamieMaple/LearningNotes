package hard

func dailyTemperatures(temperatures []int) []int {
	r := make([]int, len(temperatures))
	var stack []int

	for k, v := range temperatures {
		for {
			if len(stack) <= 0 {
				break
			}

			prevIndex := stack[len(stack)-1]
			if temperatures[prevIndex] >= v {
				break
			}

			stack = stack[:len(stack)-1]
			r[prevIndex] = k - prevIndex
		}
		stack = append(stack, k)
	}

	return r
}
