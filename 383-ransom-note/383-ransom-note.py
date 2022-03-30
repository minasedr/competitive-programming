class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        freq = Counter(magazine)
        
        for ran in ransomNote:
            if ran in freq and freq[ran]:
                freq[ran] -=1
            else:
                return False
        return True