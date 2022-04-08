class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for n in tokens:
            if n not in '+-/*':
                stack.append(int(n))
            else:
                x, y = stack.pop(), stack.pop()
                res = int(eval(f"{y}{n}{x}"))
                stack.append(res)
                    
        return stack[0]