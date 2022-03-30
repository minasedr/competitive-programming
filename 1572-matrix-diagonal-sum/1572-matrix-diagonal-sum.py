class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n, m, tot = len(mat), len(mat[0]), 0
        
        for i in range(n):
            tot += mat[i][i]
            tot += mat[i][m-i-1]
            
        if n%2==1: tot -= mat[n//2][n//2]
            
        return tot