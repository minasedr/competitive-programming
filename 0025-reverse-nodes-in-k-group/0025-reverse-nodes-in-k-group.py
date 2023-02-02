# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        
        left = 0
        right = 0
        a = []
        r = []
        while head:
    
            a.append(head.val)
            head = head.next
            
            if right - left + 1 == k:
                r.extend(a[::-1])
                left = right + 1
                a = []
            right += 1
        r.extend(a)
        
        head = None
        last = None
        
        for x in r:
            node = ListNode(x)
            if head is None:
                head = node
                last = node
            else:
                last.next = node
                last = node
        return head
                
            