class Solution:
    def checkValidString(self, s: str) -> bool:
        lmin = lmax = 0
        
        for i in s:
            if i == '(': lmin, lmax = lmin+1, lmax+1
            elif i == ')': lmin, lmax = lmin-1, lmax-1
            else: lmin, lmax = lmin-1, lmax+1
            
            if lmax < 0: return False
            if lmin < 0: lmin = 0
                
        return lmin == 0