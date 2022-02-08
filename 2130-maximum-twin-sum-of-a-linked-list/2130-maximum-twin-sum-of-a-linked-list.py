# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        node, stack, big = head, [], 0
  
        while node:
            stack.append(node.val)
            node = node.next
            
        n = len(stack) - 1
        for i in range(n):
            big = max(big,stack[i]+stack[n-i])
        return big