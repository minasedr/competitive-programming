class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        
        if n*m != r*c: return mat
        
        ans, nr, nc = [[0 for _ in range(c)] for _ in range(r)], 0, 0
        
        for i in range(n):
            for j in range(m):
                if nc > c-1: nr, nc = nr + 1, 0
                ans[nr][nc] = mat[i][j]
                nc += 1
                
        return ans