class Solution:
    def isValid(self, s: str) -> bool:
        stack, left, right = [], '{([', '})]'
        
        for ch in s:
            if ch in left:
                stack.append(ch)
            else:
                if not stack: return False
                elif left.index(stack.pop()) != right.index(ch):
                    return False
                
        return False if stack else True