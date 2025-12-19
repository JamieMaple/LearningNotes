package main

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	head := &ListNode{}
	l1 := list1
	l2 := list2
	l3 := head

	for {
		if l1 == nil {
			l3.Next = l2
			break
		} else if l2 == nil {
			l3.Next = l1
			break
		}

		if l1.Val > l2.Val {
			l3.Next = &ListNode{Val: l2.Val}
			l2 = l2.Next
		} else {
			l3.Next = &ListNode{Val: l1.Val}
			l1 = l1.Next
		}

		l3 = l3.Next
	}

	return head.Next
}
