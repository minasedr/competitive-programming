class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for n in tokens:
            if n not in '+-/*':
                stack.append(int(n))
            else:
                x, y = stack.pop(), stack.pop()
                if n == '+': stack.append(y+x)
                elif n == '-': stack.append(y-x)
                elif n == '*': stack.append(y*x)
                else: stack.append(int(y/x))
                    
        return stack[0]