class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        ans, visited = set(), set()
        
        for i in range(len(s)):
            cur = s[i:i+10]
            if cur in visited: ans.add(cur)
            visited.add(cur)
            
        return ans