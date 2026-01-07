package normal

func levelOrder(root *TreeNode) [][]int {
	r := [][]int{}

	if root == nil {
		return r
	}

	queue := [][]*TreeNode{
		{root},
	}

	for {
		if len(queue) <= 0 {
			break
		}

		q := queue[0]
		ro := []int{}

		q0 := []*TreeNode{}
		for _, node := range q {
			if node == nil {
				continue
			}

			ro = append(ro, node.Val)
			q0 = append(q0, node.Left, node.Right)
		}

		if len(ro) > 0 {
			r = append(r, ro)
		}
		if len(q0) > 0 {
			queue = append(queue, q0)
		}
		queue = queue[1:]
	}

	return r
}
