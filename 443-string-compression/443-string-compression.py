class Solution:
    def compress(self, chars: List[str]) -> int:   
        s = ""
        l = r = 0
        n = len(chars)
        
        if n == 1:
            return n
    
        while r < n:
            
            while r < n and chars[r] == chars[l]:
                r += 1
            leng = r - l
            s += chars[l]
            if leng > 1:
                s += str(leng)
            l = r
        chars[:] = list(s)
        return len(chars)