class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans, past_n, curr_n = 0, 0, 0
        
        for n in nums:
            if n == 0:
                ans = max(past_n + curr_n, ans)
                past_n = curr_n
                curr_n = 0
            else:
                curr_n += 1
        
        ans = max(past_n + curr_n, ans)
        return ans if ans < len(nums) else ans - 1