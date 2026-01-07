package easy

import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// 1. 暴力解
func getTreeDepth1(root *TreeNode, depth int) int {
	if root == nil {
		return depth
	}

	lDepth := getTreeDepth(root.Left, depth+1)
	rDepth := getTreeDepth(root.Right, depth+1)

	if lDepth > rDepth {
		return lDepth
	}

	return rDepth
}
func diameterOfBinaryTree1(root *TreeNode) int {
	if root == nil {
		return 0
	}

	lDepth := getTreeDepth(root.Left, 0)
	rDepth := getTreeDepth(root.Right, 0)

	v := lDepth + rDepth

	lv := diameterOfBinaryTree(root.Left)
	rv := diameterOfBinaryTree(root.Right)

	return int(math.Max(float64(v), math.Max(float64(lv), float64(rv))))
}

// 2 最优解
func diameterOfBinaryTree(root *TreeNode) int {
	r := 0
	var depth func(node *TreeNode) int

	depth = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		ld := depth(node.Left)
		rd := depth(node.Right)

		r = maxInt(r, ld+rd+1)

		return maxInt(ld, rd) + 1
	}

	depth(root)

	return r - 1
}
