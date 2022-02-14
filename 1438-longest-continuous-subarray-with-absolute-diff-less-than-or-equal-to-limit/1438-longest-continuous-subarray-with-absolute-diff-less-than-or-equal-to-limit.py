class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxQueue = deque()
        minQueue = deque()
        l = r = 0
        n, longest = len(nums), 0
        
        while r < n:
            while minQueue and (nums[minQueue[-1]] >= nums[r]):
                minQueue.pop()
            minQueue.append(r)

            while maxQueue and (nums[maxQueue[-1]] <= nums[r]):
                maxQueue.pop()
            maxQueue.append(r)

            while (nums[maxQueue[0]] - nums[minQueue[0]]) > limit:
                l += 1
                if l > minQueue[0]:
                    minQueue.popleft()
                if l > maxQueue[0]:
                    maxQueue.popleft()
            
            longest = max(longest, r - l + 1)
            r += 1
 
        return longest