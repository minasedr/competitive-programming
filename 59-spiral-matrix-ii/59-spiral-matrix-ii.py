class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0] * n for _ in range(n)]
        x, y, dx, dy, inc = 0, 0, 0, 1, 1
        
        for _ in range(n**2):
            if not(0<=x+dx<n) or not(0<=y+dy<n) or res[x+dx][y+dy] != 0:
                dx, dy = dy, -dx
                
            res[x][y] = inc
            inc += 1
            x, y = x+dx, y+dy
            
        return res