# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = tail = None
        carry = 0
        
        while (l1 or l2 or carry):
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            aggr = val1 + val2 + carry

            carry = aggr // 10
            aggr %= 10

            node = ListNode(aggr)

            if not head:
                head = node
                tail = head
            else:
                tail.next = node
                tail = tail.next
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
           

        return head