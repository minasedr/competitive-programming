class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        j, n = 0, len(s)
        for i in t:
            if not s: return True
            j = j + 1 if j < n and i == s[j] else j
            
        return True if j == n else False