class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        store, stack = {}, []
        
        for i in nums2:
            while stack and stack[-1] < i:
                store[stack.pop()] = i
            stack.append(i)
            
        return [store.get(j,-1) for j in nums1]