class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        first = demo = prev = head
        length = 0
        
        while head:
            length += 1
            head = head.next
        if length <= 1:
            return head
        
        if length == n:
            first = first.next
            return first
        
        j = 0
        while j < length - n:
            prev = demo
            demo = demo.next
            j += 1
        prev.next = demo.next
        return first
