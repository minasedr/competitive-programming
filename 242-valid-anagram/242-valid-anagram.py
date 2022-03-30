class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq1, freq2 = Counter(s), Counter(t)
        
        if len(freq1) != len(freq2): return False
        
        for i in s:
            if freq1[i] != freq2[i]:
                return False
        return True