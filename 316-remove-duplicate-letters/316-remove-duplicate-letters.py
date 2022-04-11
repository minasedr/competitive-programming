class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack, visited, n = [], set(), len(s)-1
        store = {x:idx for idx, x in enumerate(s)}
        
        for i, ch in enumerate(s):
            if ch in visited: continue
            while stack and store[stack[-1]] > i and stack[-1] >= ch:
                visited.remove(stack[-1])
                stack.pop()
                
            stack.append(ch)
            visited.add(ch)
            
        return ''.join(stack)