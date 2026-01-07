package easy

// 1. 自己写法
func maxDepth1(root *TreeNode) int {
	return maxDepthT(root, 0)
}

func maxDepthT(root *TreeNode, depth int) int {
	if root == nil {
		return depth
	}
	depth += 1
	lDepth := maxDepthT(root.Left, depth)
	rDepth := maxDepthT(root.Right, depth)
	if lDepth > rDepth {
		return lDepth
	}
	return rDepth
}

// 2. 优化参数后的写法
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxDepth(root *TreeNode) int {
	var depth func(node *TreeNode) int
	depth = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		l := depth(node.Left)
		r := depth(node.Right)

		r = maxInt(r, l+r+1)

		return maxInt(l, r) + 1
	}
	if root == nil {
		return 0
	}
	ld := maxDepth(root.Left)
	rd := maxDepth(root.Right)

	if ld > rd {
		return ld + 1
	}
	return rd + 1
}
