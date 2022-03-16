class Solution:
    def hIndex(self, citations: List[int]) -> int:
        ans, left, right, n = 0, 0, len(citations) - 1, len(citations)
        
        while (left <= right):
            mid = (left + right) // 2
            if citations[mid] >= n-mid:
                ans, right = n-mid , mid - 1
            else:
                left = mid + 1
                
        return ans