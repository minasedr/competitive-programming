class Solution:
    def calculate(self, s: str) -> int:
        s = "".join(s.split())
        # s = re.split('\+|\-', s)
    
        first, second, i, n = [], [], 0, len(s)
        ops = "+-*/"
        stack = ["" for i in range(len(s))]
        j = 0
        for x in s:
            if x.isdigit():
                stack[j]  += x
            else:
                j += 1
                stack[j] = x
                j += 1
        s = stack
        while i < n:
            if s[i] not in ops[2:]:
                if s[i].isdigit():
                    first.append(int(s[i]))
                else:
                    first.append(s[i])
            else:
                if s[i] == ops[2]:
                    first.append(first.pop() * int(s[i+1]))
                    i += 1
                elif s[i] == ops[3]:
                    first.append(first.pop() // int(s[i+1]))
                    i += 1
            i += 1
        j = 0
        while j < len(first):
            if str(first[j]) not in ops[:2]:
                second.append(first[j])
            else:
                if first[j] == ops[1]:
                    second.append(second.pop() - first[j+1])
                    j += 1
                elif first[j] == ops[0]:
                    second.append(second.pop() + first[j+1])
                    j += 1
            j += 1

        return ''.join(map(str,second))
