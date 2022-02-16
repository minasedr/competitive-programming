# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        arr = []
        node = head
        while node:
            arr.append(node)
            node = node.next
        for i in range(len(arr)):
            j = i - 1
            key = arr[i].val
            while j >= 0 and key < arr[j].val:
                arr[j+1].val = arr[j].val
                j -= 1
            arr[j+1].val = key
        return head