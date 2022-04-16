class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        N, M = len(nums), ((2*k)+1)
        prefix, ans = [0] * N, [-1] * N
        
        for i in range(N):
            prefix[i] = prefix[i-1] + nums[i]
                
        for i in range(N):
            if i+k < N and i-k >= 0:
                left = 0 if not i-k else prefix[i-k-1]
                ans[i] = (prefix[i+k] - left)//M
                
        return ans