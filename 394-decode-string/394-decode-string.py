class Solution:
    def decodeString(self, s: str) -> str:
        digits, stack, sub, digit = [] , [], "", ""
        
        for i in s:
            if i.isdigit():
                digit += i
            elif i != ']':
                if i == '[':
                    digits.append(int(digit))
                    digit = ""
                stack.append(i)
            else:
                while stack and stack[-1] != '[':
                    sub += str(stack.pop())
                stack.pop()
                stack.append(digits.pop() * sub)
                sub = ""
        
        stack[:] = stack[::-1]
        
        return ''.join(stack)[::-1]