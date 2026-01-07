package easy

func diffTree(root1 *TreeNode, root2 *TreeNode) bool {
	if root1 == nil || root2 == nil {
		return root1 == root2
	}
	return root1.Val == root2.Val && diffTree(root1.Left, root2.Right) && diffTree(root1.Right, root2.Left)
}
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return diffTree(root.Left, root.Right)
}
