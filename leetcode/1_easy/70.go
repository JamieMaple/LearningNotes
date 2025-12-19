package main

// 1. 自己想的动态规划
func climbStairsTempl(n int, m map[int]int) int {
	if v, ok := m[n]; ok {
		return v
	}

	r := climbStairsTempl(n-1, m) + climbStairsTempl(n-2, m)
	m[n] = r

	return r
}

func climbStairs1(n int) int {
	m := make(map[int]int, n)
	m[1] = 1
	m[2] = 2
	return climbStairsTempl(n, m)
}

// 2. 利用上次计算结果
func climbStairs(n int) int {
	r := 0
	f := 1
	d := 0

	for i := 0; i <= n; i++ {
		r = f + d
		f = d
		d = r
	}

	return r
}
