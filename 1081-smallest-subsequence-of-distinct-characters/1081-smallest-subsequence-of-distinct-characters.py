class Solution:
    def smallestSubsequence(self, s: str) -> str:
        occ = {x:i for i, x  in enumerate(s)}
        visited, stack = set(), []
        
        for i, ch in enumerate(s):
            if ch in visited:
                continue
            while stack and occ[stack[-1]] >= i and stack[-1] > ch:
                visited.remove(stack.pop())
            visited.add(ch)
            stack.append(ch)
        return ''.join(stack)