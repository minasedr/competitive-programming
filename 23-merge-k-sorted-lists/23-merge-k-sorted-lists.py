# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        heap = []
        
        for idx, node in enumerate(lists):
            if node:
                heap.append((node.val, idx, node))
            
        heapq.heapify(heap)
        
        head = ListNode()
        curr = head
        
        while heap:
            small = heapq.heappop(heap)
            curr.next = small[2]
            curr = curr.next
            
            if curr.next:
                demo = curr.next
                heapq.heappush(heap,(demo.val, small[1], demo))
      
        return head.next