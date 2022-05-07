class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack, k = [], 0
        
        for p in pushed:
            stack.append(p)
            while stack and stack[-1] == popped[k]:
                stack.pop()
                k += 1
        return k == len(popped) 