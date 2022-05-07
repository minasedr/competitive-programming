class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        pairs = {'+', '-', '/', '*'}
        for token in tokens:
            if token not in pairs:
                stack.append(int(token))
            else:
                x, y = stack.pop(), stack.pop()
                if token == '+':
                    stack.append(y+x)
                elif token == '-':
                    stack.append(y-x)
                elif token == '/':
                    stack.append(int(y/x))
                else:
                    stack.append(x*y)
        return sum(stack)