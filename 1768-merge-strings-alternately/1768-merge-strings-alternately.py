class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        l, r, n, m, ans= 0, 0, len(word1), len(word2), ""
        
        while l < n and r < m:
            ans += word1[l]+word2[r]
            l, r = l+1, r+1
            
        while l < n:
            ans, l = ans + word1[l], l+1
            
        while r < m:
            ans, r = ans + word2[r], r+1
            
        return ans