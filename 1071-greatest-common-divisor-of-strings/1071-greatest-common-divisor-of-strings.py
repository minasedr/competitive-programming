class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        n, m = len(str1), len(str2)
        
        for i in range(min(n, m), -1, -1):
            k1 = str1.count(str1[:i])
            k2 = str2.count(str1[:i])
            
            if k1 * i == n and k2 * i == m:
                return str1[:i]
        return ''