class Solution:
    def minOperations(self, logs: List[str]) -> int:
        stack = []
        for i in logs:
            if i[-2] == '.':
                if len(i) >= 3 and i[-3] == '.':
                    if stack:
                        stack.pop()
                        
            else:
                stack.append(1)
        return len(stack)
