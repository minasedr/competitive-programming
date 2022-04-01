class Solution:
    def isValid(self, s: str) -> bool:
        stack, store = [],  {'{':'}', '(':')','[':']'}
        
        for ch in s:
            if ch in '{[(':
                stack.append(ch)
            else:
                if not stack: return False
                elif store[stack.pop()] != ch:
                    return False
               
        return False if stack else True