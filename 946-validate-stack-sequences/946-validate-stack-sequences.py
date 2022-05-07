class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack, ans, k = [], [], 0
        
        for p in pushed:
            while stack and stack[-1] == popped[k]:
                ans.append(stack.pop())
                k += 1
            stack.append(p)
            
        ans.extend(stack[::-1])
        for a, p in zip(ans, popped):
            if a != p: return False
        return True
