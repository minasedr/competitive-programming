class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n, memo = len(questions), {}
        
        def dfs(i):
            if i >= n: return 0
            if i in memo: return memo[i]
            memo[i] = max(
                dfs(i+questions[i][1]+1) + questions[i][0],
                dfs(i+1)
            )
            return memo[i]
        
        return dfs(0)