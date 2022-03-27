class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2: return True
        ch = []
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                ch.append(i)
                
        if len(ch) != 2: return False
        x, y = ch
        if s1[y] == s2[x] and s1[x] == s2[y]: return True