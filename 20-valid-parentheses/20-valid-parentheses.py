class Solution:
    def isValid(self, s: str) -> bool:
        store = { ')':'(', ']': '[', '}': '{'}
        
        stack = []
        for ch in s:
            if ch not in store:
                stack.append(ch)
            else:
                if not stack: return False
                elif stack[-1] != store[ch]: return False
                stack.pop()
            
        return True if not stack else False
                