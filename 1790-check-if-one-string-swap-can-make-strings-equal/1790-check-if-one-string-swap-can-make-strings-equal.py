class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2: return True
        ch = []
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                ch.append(i)
                
        if len(ch) != 2: return False
        x, y = ch
        s1 = s1[:x] + s1[y] + s1[x+1:y] + s1[x] + s1[y+1:]
        if s1 == s2: return True