package easy

func postorderTraversal(root *TreeNode) []int {
	result := []int{}
	if root == nil {
		return result
	}
	l := postorderTraversal(root.Left)
	r := postorderTraversal(root.Right)
	result = append(result, l...)
	result = append(result, r...)
	result = append(result, root.Val)

	return result

}
