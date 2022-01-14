class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operators = '+-*/'
        stack = []
        for i in range(len(tokens)):
            if tokens[i] not in operators:
                stack.append(int(tokens[i]))
            else:
                if tokens[i] == '+':
                    stack.append(stack.pop() + stack.pop())
                elif tokens[i] == '-':
                    tmp = stack.pop()
                    stack.append(stack.pop() - tmp)
                elif tokens[i] == '*':
                    stack.append(stack.pop() * stack.pop())
                elif tokens[i] == '/':
                    tmp = stack.pop()
                    stack.append(int(stack.pop()/tmp))
        return sum(stack)
