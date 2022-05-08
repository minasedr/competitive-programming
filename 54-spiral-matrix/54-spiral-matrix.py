class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        def dfs(i, j):
            if i >= M or j >= N or i < 0 or j < 0 or matrix[i][j] == '#':
                return
            res.append(matrix[i][j])
            matrix[i][j] = '#'
            
            if j+1 >= i: dfs(i, j+1)
            dfs(i+1, j)
            dfs(i, j-1)
            dfs(i-1, j)
            
        M, N, res = len(matrix), len(matrix[0]), []
        dfs(0, 0)
        
        return res