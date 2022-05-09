class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        N, M = len(haystack), len(needle)
        
        for i in range(N-M+1):
            j, k = i, 0
            while k < M and haystack[j] == needle[k]:
                k, j = k+1, j+1
                
            if k == M: return i
        return -1