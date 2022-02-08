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
        stack, index, node = deque(), 0, head
        
        while node:
            stack.append(node.val)
            node = node.next
            
        node = head
        while node:
            if index % 2 == 0:
                node.val = stack.popleft()
            else:
                node.val = stack.pop()
            index += 1
            node = node.next
            
        return head
                