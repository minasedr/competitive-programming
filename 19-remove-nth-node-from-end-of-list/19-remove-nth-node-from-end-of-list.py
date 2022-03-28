# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        slow = fast = head
        
        for i in range(n):
            fast = fast.next
        if not fast: return slow.next
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next
            
        d = slow.next
        slow.next, d = d.next, None
        
        return head
