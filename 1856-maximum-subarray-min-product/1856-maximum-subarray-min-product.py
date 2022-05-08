class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        prefix, stack, res, N = [0], [], 0, len(nums)
        
        for n in nums:
            prefix.append(prefix[-1] + n)
            
        for idx, num in enumerate(nums):
            newStart = idx
            while stack and stack[-1][1] > num:
                start, val = stack.pop()
                total = prefix[idx] - prefix[start]
                res = max(res, val * total)
                newStart = start
                
            stack.append((newStart, num))
        
        for start, val in stack:
            total = prefix[N] - prefix[start]
            res = max(res, total * val)
            
        return res % (10**9 + 7)