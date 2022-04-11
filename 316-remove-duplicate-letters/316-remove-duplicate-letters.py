class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack, visited = [], set()
        store = {x:idx for idx, x in enumerate(s)}
        
        for i, ch in enumerate(s):
            if ch in visited: continue
            while stack and store[stack[-1]] > i and stack[-1] >= ch:
                visited.remove(stack.pop())
                
            stack.append(ch)
            visited.add(ch)
            
        return ''.join(stack)