package easy

import (
	"math"
)

// 1. 暴力解法
func maxProfit1(prices []int) int {
	max := 0

	for i := range prices {
		for j := i + 1; j < len(prices); j++ {
			r := int(math.Max(0, float64(prices[j]-prices[i])))

			if r > max {
				max = r
			}
		}
	}

	return max
}

// fx -> 当前最小
// 2. 动态规划
func maxProfit2(prices []int) int {
	if len(prices) <= 0 {
		return 0
	}

	m := make(map[int]int, len(prices))

	m[0] = prices[0]

	for k, p := range prices {
		if k == 0 {
			m[0] = p
		}

		if p < m[k-1] {
			m[k] = p
		} else {
			m[k] = m[k-1]
		}
	}

	r := 0
	for k, p := range prices {
		if p-prices[k] < r {
			r = p - prices[k]
		}
	}

	return r
}

// 3. 最优解
func maxProfit(prices []int) int {
	if len(prices) <= 0 {
		return 0
	}
	minVal := prices[0]
	maxProfitVal := 0

	for _, p := range prices {
		if minVal > p {
			minVal = p
		}
		v := p - minVal
		if v > maxProfitVal {
			maxProfitVal = v
		}
	}

	return maxProfitVal
}
