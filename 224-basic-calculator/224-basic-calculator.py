class Solution:
    def calculate(self, s: str) -> int:
        def func(i):
            def operate(v, sign):
                if sign == '+': stack.append(v)
                elif sign == '-': stack.append(-v)
            
            cur, sign, stack = 0, '+', []

            while i < len(s):
                if s[i].isdigit():
                    cur = cur * 10 + int(s[i])
                elif s[i] in '+-':
                    operate(cur, sign)
                    cur, sign = 0, s[i]
                elif s[i] == '(':
                    cur, j = func(i+1)
                    i = j-1
                elif s[i] == ')':
                    operate(cur, sign)
                    return sum(stack), i+1
                i += 1
            operate(cur, sign)
            return sum(stack)
        return func(0)