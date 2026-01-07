package easy

// 1. 自己想的
func moveZeroes1(nums []int) {
	i := 0
	j := 0
	for {
		if nums[i] != 0 {
			i += 1
		}
		if nums[j] == 0 {
			j += 1
		}

		if j >= len(nums) || i >= len(nums) {
			break
		}
		if nums[i] == 0 && nums[j] != 0 {
			if i < j {
				// swap i and j
				nums[i], nums[j] = nums[j], nums[i]
			} else {
				j = i
			}
		}
	}
}

// 2. leetcode 最优解
func moveZeroes(nums []int) {
	i := 0 // 左边以前的都是非0数
	j := 0 // 左边到i之间都是0
	for {
		if j >= len(nums) {
			break
		}
		if nums[j] != 0 {
			nums[i], nums[j] = nums[j], nums[i]
			i++
		}
		j++
	}
}
