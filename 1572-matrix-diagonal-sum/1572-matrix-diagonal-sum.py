class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        visited, n, m, total = set(), len(mat), len(mat[0]), 0
        
        for i in range(n):
            for j in range(m):
                if i==j or i+j == n-1:
                    if (i,j) in visited:
                        continue
                    total += mat[i][j]
                    visited.add((i,j))
        return total