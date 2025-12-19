package main

func maxDepth(root *TreeNode) int {
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
