class Solution:
    def isValid(self, s: str) -> bool:
        stack = deque()
        opening = '({['
        closing = ')}]'
        for i in s:
            if i in opening:
                stack.append(i)
            elif i in closing:
                if len(stack) == 0:
                    return False
                if closing.index(i) != opening.index(stack.pop()):
                    return False
    
        if not stack:
            return True
