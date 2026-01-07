package normal

func convertBST(root *TreeNode) *TreeNode {
	sum := 0
	var dfs func(root *TreeNode) *TreeNode

	dfs = func(root *TreeNode) *TreeNode {
		if root == nil {
			return nil
		}
		node := *root

		node.Right = dfs(node.Right)

		sum += node.Val
		node.Val = sum

		node.Left = dfs(node.Left)

		return &node
	}

	return dfs(root)
}
