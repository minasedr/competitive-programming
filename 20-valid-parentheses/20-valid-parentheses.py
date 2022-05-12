class Solution:
    def isValid(self, s: str) -> bool:
        G = {'(':')', '{':'}', '[':']'}
        stack = []
        
        for ch in s:
            if ch in G:
                stack.append(ch)
            else:
                if (not stack) or (stack and G[stack.pop()] != ch):
                    return False
        return len(stack) == 0