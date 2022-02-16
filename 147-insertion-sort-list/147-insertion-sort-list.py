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
            arr.append(node.val)
            node = node.next
        for i in range(len(arr)):
            j = i - 1
            key = arr[i]
            while j >= 0 and key < arr[j]:
                arr[j+1] = arr[j]
                j -= 1
            arr[j+1] = key
        sec = head
        for i in arr:
            sec.val = i
            sec = sec.next
        return head