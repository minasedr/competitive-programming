class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s, t = Counter(s), Counter(t)
        
        for i in t:
            if t[i] == s[i]: t[i] = 0
            else: return i