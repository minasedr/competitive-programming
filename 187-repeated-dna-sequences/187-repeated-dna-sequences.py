class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        ans, visited, n = set(), set(), len(s)
        
        for i in range(n):
            cur = s[i:i+10]
            if cur in visited:
                ans.add(cur)
            visited.add(cur)
            
        return ans