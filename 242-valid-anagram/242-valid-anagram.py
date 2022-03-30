class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq1, freq2 = Counter(s), Counter(t)
        
        for i in t:
            if i in freq1 and freq1[i]:
                freq1[i] -=1
            else: return False
        
        for i in s:
            if i in freq2 and freq2[i]:
                freq2[i] -=1
            else: return False
            
        return True