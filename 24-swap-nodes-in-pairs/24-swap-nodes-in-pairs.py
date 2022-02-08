# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        slow = head
        fast = head.next
        while fast.next and fast.next.next:
            slow.val, fast.val = fast.val, slow.val
            slow = fast.next
            fast = slow.next
        slow.val, fast.val = fast.val, slow.val

        return head