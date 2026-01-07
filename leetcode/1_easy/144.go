package easy

func preorderTraversal(root *TreeNode) []int {
	r := []int{}
	if root == nil {
		return r
	}

	r = append(r, root.Val)
	lr := preorderTraversal(root.Left)
	rr := preorderTraversal(root.Right)

	r = append(r, lr...)
	r = append(r, rr...)

	return r
}
