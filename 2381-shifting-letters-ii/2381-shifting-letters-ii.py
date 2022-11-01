class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        pref = [0] * (n + 1)
        
        for x in shifts:
            pref[x[0]] += (1 if x[2] == 1 else -1)
            pref[x[1] + 1] += (-1 if x[2] == 1 else 1)
            
        for i in range(1, n + 1):
            pref[i] += pref[i - 1];
        
        s = list(s)
        for i in range(n):
            s[i] = chr((ord(s[i]) - ord('a') + pref[i]) % 26 + ord('a'))
            
        return "".join(s)