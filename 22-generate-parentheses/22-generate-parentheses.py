class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack, res = [], []
        
        def generate(openN, closedN):
            
            if openN == closedN == n:
                res.append("".join(stack))
            
            if openN < n:
                stack.append('(')
                generate(openN + 1, closedN)
                stack.pop()
            
            if closedN < openN:
                stack.append(')')
                generate(openN, closedN + 1)
                stack.pop()
                
        generate(0,0)
        return res