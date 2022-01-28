# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        demo = []
        if head == None:
            return None
        
        while head:
            demo.append(head)
            head = head.next
            
        for i in range(len(demo) - 1, 0, -1):
            demo[i].next = demo[i - 1]
            demo[i - 1].next = None
        
        return demo[-1]
        
