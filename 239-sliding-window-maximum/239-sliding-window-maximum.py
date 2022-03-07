class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        heap, ans = [], []
        
        for i in range(k):
            heappush(heap, (-nums[i], i))
            
        ans.append(-heap[0][0])
        
        for i in range(k, len(nums)):
            while heap and i - heap[0][1] >= k:
                heappop(heap)
                
            heappush(heap, (-nums[i], i))
            ans.append(-heap[0][0])
            
        return ans