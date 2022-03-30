class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq1, freq2 = Counter(s), Counter(t)
        
        if len(freq1) != len(freq2): return False
        
        return freq1 == freq2