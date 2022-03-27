class Solution:
    def reverseWords(self, s: str) -> str:
        ans, inter = [], []
        
        for x in s:
            inter = [x] + inter
            if x == " ":
                ans += inter
                inter = []
        ans += [' '] + inter
        
        return ''.join(ans).strip()
    