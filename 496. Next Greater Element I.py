class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack, result = [], []
        greater = {}
        n = len(nums2)
        for i in range(n):
            while stack and stack[-1] < nums2[i]:
                key = stack.pop()
                greater[key] = nums2[i]
            stack.append(nums2[i])
            
        for j in stack:
            greater[j] = -1
            
        for k in nums1:
            result.append(greater[k])
            
        return result
