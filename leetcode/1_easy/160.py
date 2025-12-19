# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
#         existed = set()
#         currentNode = headA
#         while currentNode:
#             existed.add(currentNode)
#             currentNode = currentNode.next
            
#         currentNode = headB
#         while currentNode:
#             if currentNode in existed:
#                 return currentNode
#             currentNode = currentNode.next
        
#         return None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        pA = headA
        pB = headB

        while True:
            if pA == pB:
                return pA

            if pA == None and pB == None:
                return None
            
            if pA == None:
                pA = headB
            elif pB == None:
                pB = headA
            else:
                pA = pA.next
                pB = pB.next