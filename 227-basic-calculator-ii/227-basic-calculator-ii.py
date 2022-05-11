class Solution:
    def calculate(self, s: str) -> int:
        cur, stack, sign = 0, [], '+'

        def operate(v, sign):
            if sign == '+': stack.append(v)
            elif sign == '-': stack.append(-v)
            elif sign == '*': stack.append(stack.pop() * v)
            elif sign == '/': stack.append(int(stack.pop()/v))

        for n in s:
            if n.isdigit():
                cur = cur * 10 + int(n)
            elif n in '+-*/':
                operate(cur, sign)
                cur, sign = 0, n

        operate(cur, sign) 
        return sum(stack)