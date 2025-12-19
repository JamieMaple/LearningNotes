package main

func countBitsSingle(n int) int {
	r := 0

	for {
		if n == 0 {
			break
		}
		if n&1 == 1 {
			r += 1
		}
		n >>= 1
	}

	return r
}

func countBits(n int) []int {
	result := make([]int, n+1)
	for i := 0; i <= n; i++ {
		result[i] = countBitsSingle(i)
	}
	return result
}
