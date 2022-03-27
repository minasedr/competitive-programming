class Solution:
    def reverseWords(self, s: str) -> str:
        inter, ans = s.split(), ""
        
        for i in inter:
            ans += ' ' + ''.join(i[::-1])
            
        return ans.strip()