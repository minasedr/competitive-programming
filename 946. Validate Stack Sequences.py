class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        
        psh, pp = [], []
        n = len(popped)
        
        while pushed:
            psh.append(pushed.pop(0))
            while psh and psh[-1] == popped[0]:
                popped.pop(0)
                pp.append(psh.pop())
        if len(pp) == n:
            return True
        return False
