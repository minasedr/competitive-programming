# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        
        stack = []
        index = 0
        node = head
        while node:
            stack.append(node.val)
            node = node.next
        node = head
        i = 0
        while node:
            if index % 2 == 0:
                node.val = stack[i]
                node = node.next
                i += 1
            else:
                node.val = stack.pop()
                node = node.next
            index += 1
        return head
                