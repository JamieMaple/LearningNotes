package normal

func flatten(root *TreeNode) {
	if root == nil {
		return
	}

	pl := preorderTree(root)

	for {
		if len(pl) <= 0 {
			break
		}

		current := pl[0]
		pl = pl[1:]

		var next *TreeNode
		if len(pl) > 0 {
			next = pl[0]
		}
		current.Left = nil
		current.Right = next
	}
}

func preorderTree(root *TreeNode) []*TreeNode {
	result := []*TreeNode{}
	if root == nil {
		return result
	}
	result = append(result, root)
	l := preorderTree(root.Left)
	r := preorderTree(root.Right)

	result = append(result, l...)
	result = append(result, r...)

	return result
}
