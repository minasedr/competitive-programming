class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack, store = [], {}
        
        for num in nums2:
            while stack and stack[-1] < num:
                store[stack.pop()] = num
            stack.append(num)
        
        return [store[n] if n in store else -1 for n in nums1]