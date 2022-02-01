class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        x, y, dx, dy = 0,0,1,0

        result = []
        for _ in range(m*n):
            if not 0 <= x+dx < n or not 0 <= y+dy < m or matrix[y+dy][x+dx] == "#":
                dx, dy = -dy, dx
                
            result.append(matrix[y][x])
            matrix[y][x] = '#'
            x, y = x+dx, y+dy
        return result
