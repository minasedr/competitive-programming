class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 == 1: return False
        
        lstack, rstack = [], []
        
        for i in range(len(s)):
            if locked[i] == '0': rstack.append(i)
            elif s[i] == '(': lstack.append(i)
            elif s[i] == ')':
                if lstack: lstack.pop()
                elif rstack: rstack.pop()
                else: return False
                
        while lstack and rstack:
            if rstack.pop() < lstack.pop():
                return False
            
        return not lstack