class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = len(s)
        def dfs(i):
            if i >= n:
                return ""
            return dfs(i + 1) + s[i]
        
        s[:] = dfs(0)