# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        first = head
        if not head:
            return None
        
        elif not head.next:
            return head
        
        demo = head.next
        while demo:
            while head.val == demo.val:
                demo = demo.next 
                if demo == None:
                    break
            head.next = demo
            head = demo
        return first
