class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        prefix, ans = [], [-1] * len(nums)
        
        for idx, num in enumerate(nums):
            if prefix:
                prefix.append(prefix[-1]+num)
            else: prefix.append(num)
                
        for i in range(len(nums)):
            if i+k < len(nums) and i-k >= 0:
                left = 0 if i-k == 0 else prefix[i-k-1]
                ans[i] = (prefix[i+k] - left)//((2*k)+1)
                
        return ans