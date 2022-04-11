class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        rev = lambda x: x[::-1]
        invt = lambda x: ''.join(['1' if i=='0' else '0' for i in x])
        
        def dfs(s, i):
            if i >= n: return s
            return dfs(s+'1'+rev(invt(s)), i+1)
        
        return dfs('0',1)[k-1]