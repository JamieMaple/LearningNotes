package normal

// [3,9,20,15,7] -> 先序第一个，确定位根节点
// [9,3,15,20,7] -> 以3为分界点，左右两棵树递归

func buildHelper(preorder, inorder []int) *TreeNode {
	if len(preorder) <= 0 || len(preorder) <= 0 {
		return nil
	}

	val := preorder[0]
	node := &TreeNode{
		Val: val,
	}

	// find nodeInorderIndex
	nodeInorderIndex := 0
	for k, v := range inorder {
		if v == val {
			nodeInorderIndex = k
			break
		}
	}

	leftSize := nodeInorderIndex

	leftPreStart := 1
	leftPreEnd := leftSize
	leftInStart := 0
	leftInEnd := nodeInorderIndex - 1

	rightPreStart := leftSize + 1
	rightPreEnd := len(preorder)
	rightInStart := nodeInorderIndex + 1
	rightInEnd := len(inorder)

	node.Left = buildHelper(preorder[leftPreStart:leftPreEnd+1], inorder[leftInStart:leftInEnd+1])
	node.Right = buildHelper(preorder[rightPreStart:rightPreEnd], inorder[rightInStart:rightInEnd])

	return node
}

func buildTree(preorder, inorder []int) *TreeNode {
	if len(preorder) <= 0 {
		return nil
	}

	root := buildHelper(preorder, inorder)

	return root
}
