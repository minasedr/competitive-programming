class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        ans = []
        for i in nums1:
            j = nums2.index(i)
            x = j + 1
            while x < len(nums2):
                if nums2[j] < nums2[x]:
                    stack.append(nums2[x])
                    break
                x += 1
            if stack:
                ans.append(stack.pop())
            else:
                ans.append(-1)
                
        return ans
