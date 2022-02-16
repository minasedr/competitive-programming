# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        store = {}
        res, stack = [], []
        demo = head
        while head:
            res.append(head.val)
            head = head.next
        for i in range(len(res)):
            while stack and res[stack[-1]] < res[i]:
                store[stack.pop()] = res[i]
            stack.append(i)
        while stack:
            store[stack.pop()] = 0
            
        return [store[x] for x in range(len(res))]
