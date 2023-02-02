class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letters, digits = [], []
        n = len(logs)
        
        for i in range(n):
            splitted = logs[i].split()
            cur = ' '.join(splitted[1:])
            if (cur[0].isdigit()):
                digits.append((cur, splitted[0]))
            else:
                letters.append((cur, splitted[0]))
        
        letters.sort()
        ans = []
        for cur, sp in letters:
            ans.append(sp + " " + cur)
        for cur, sp in digits:
            ans.append(sp + ' ' + cur)
            
        return ans