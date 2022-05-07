class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        N, ans = len(citations), 0
        
        for i in range(N):
            if citations[i] >= i + 1:
                ans = i + 1
        return ans