class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq, idx = OrderedDict(), 0
        
        for i in s:
            if i not in freq:
                freq[i] = 1
            else: freq[i] += 1
                
        for k, v in freq.items():
            if v == 1:  idx = k; break
                
        for x in range(len(s)):
            if s[x] == idx:
                return x
        return -1