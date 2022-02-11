class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        unique = set()
        l = r = long = 0
        
        while r < len(s):
            if s[r] in unique:
                long = max(long, r-l)
                while (s[l] != s[r]):
                    unique.remove(s[l])
                    l += 1
                l += 1
            unique.add(s[r])
            r += 1
            
        return max(long, r - l)