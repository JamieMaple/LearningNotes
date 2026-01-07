package easy

import (
	"math"
)

func getTreeDepth(root *TreeNode, depth int) int {
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

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}

	lDepth := getTreeDepth(root.Left, 0)
	rDepth := getTreeDepth(root.Right, 0)

	r := true
	if math.Abs(float64(lDepth-rDepth)) > 1 {
		r = false
	}
	return r && isBalanced(root.Left) && isBalanced(root.Right)
}
