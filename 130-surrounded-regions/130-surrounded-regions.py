class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n, m = len(board), len(board[0])
        visited = set()
        indices = [(x,y) for x in range(n) for y in range(m)]
        
        def dfs(row, col):
            visited.add((row,col))
            
            for dirs in DIR:
                dx, dy = row + dirs[0], col + dirs[1]
                if (dx,dy) not in visited and inbound(dx,dy) and board[dx][dy] == 'O':
                    dfs(dx,dy)
        
        DIR = [[0,1],[1,0],[-1,0],[0,-1]]
        inbound = lambda x, y: 0 <= x < n and 0 <= y < m
        
        def border(x,y):
            if 0<=x<n and (y == 0 or y == m-1):
                return True
            if 0<=y<m and (x==0 or x==n-1):
                return True
            return False
        
        for (x,y) in indices:
            if (x,y) not in visited and inbound(x,y) and border(x,y) and board[x][y] == 'O':
                dfs(x,y)  
        tbc = set(indices) - visited
        
        for (x,y) in tbc:
            if (x,y) not in visited and inbound(x,y) and board[x][y] == 'O':
                board[x][y] = 'X'
                
        return board