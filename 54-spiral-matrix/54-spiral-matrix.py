class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        M, N = len(matrix), len(matrix[0])
        x, y , dx, dy = 0, 0, 0, 1
        res = []
        
        for _ in range(M*N):
            if not(0<=x+dx<M) or not(0<=y+dy<N) or matrix[x+dx][y+dy] == '#':
                dx, dy = dy, -dx
            res.append(matrix[x][y])
            matrix[x][y] = '#'
            x, y = x+dx, y+dy
            
        return res