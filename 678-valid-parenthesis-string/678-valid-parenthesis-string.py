class Solution:
    def checkValidString(self, s: str) -> bool:
        lstack, rstack = [], []
        
        for i in range(len(s)):
            if s[i] == '(': lstack.append(i)
            elif s[i] == '*': rstack.append(i)
            else:
                if lstack: lstack.pop()
                elif rstack: rstack.pop()
                else: return False
        
        while lstack and rstack:
            if rstack.pop() < lstack.pop():
                return False
            
        return not lstack