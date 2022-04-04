class Solution:
    def interpret(self, command: str) -> str:
        ans, n = "", len(command)
        
        for i in range(n):
            if command[i] == 'G': ans += 'G'
            if command[i] == '(':
                if command[i+1] == ')':
                    ans += 'o'
                else: ans += 'al'
            
        return ans