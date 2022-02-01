# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        
        stack = []
        slow = fast = head
        if not head.next:
            return True
        
        while fast and fast.next:
            stack.append(slow.val)
            slow = slow.next
            fast = fast.next.next
              
        while slow:
            if slow.val == stack[-1]:
                stack.pop()
            slow = slow.next
            
        if not stack:
            return True
        return False
