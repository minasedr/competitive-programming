class Solution:
    def isValid(self, s: str) -> bool:
        store = {')': '(', ']': '[', '}': '{'}
        stack = []
        
        for ch in s:
            if ch not in store:
                stack.append(ch)
            elif not stack or stack[-1] != store[ch]:
                return False
            else: stack.pop()
                
        return len(stack) == 0   