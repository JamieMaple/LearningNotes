// You can edit this code!
// Click here and start typing.
package easy

import (
	"fmt"
	"math"
)

// 1. 自己想的解法，换位置
// func swap(nums []int, a, b int) {
// 	temp := nums[a]
// 	nums[a] = nums[b]
// 	nums[b] = temp
// }

// func findDisappearedNumbers(nums []int) []int {
// 	result := []int{}
// 	for k, v := range nums {
// 		for {
// 			if v == nums[v-1] {
// 				break
// 			}
// 			if v-1 == k {
// 				break
// 			}
// 			swap(nums, k, v-1)
// 		}
// 	}

// 	fmt.Println(nums)
// 	for k, v := range nums {
// 		if v-1 != k {
// 			result = append(result, k+1)
// 		}
// 	}
// 	return result
// }

// 2. 负数 鸽子笼
func findDisappearedNumbers(nums []int) []int {
	result := []int{}
	for _, v := range nums {
		v = int(math.Abs(float64(v)))
		nums[v-1] = -int(math.Abs(float64(nums[v-1])))
	}
	for k, v := range nums {
		if v > 0 {
			result = append(result, k+1)
		}
	}
	return result
}

func main() {
	nums := []int{4, 3, 2, 7, 8, 2, 3, 1}
	r := findDisappearedNumbers(nums)
	fmt.Println(r)
}
