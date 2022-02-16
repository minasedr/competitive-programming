# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        store = {}
        arr, stack = [], []
       
        while head:
            arr.append(head.val)
            head = head.next
            
        n = len(arr)
        
        for i in range(n):
            while stack and arr[stack[-1]] < arr[i]:
                store[stack.pop()] = arr[i]
            stack.append(i)
            
        while stack:
            store[stack.pop()] = 0
            
        return [store[x] for x in range(n)]
