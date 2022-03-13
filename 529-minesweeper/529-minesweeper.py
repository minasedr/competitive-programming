class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        n, m = len(board), len(board[0])
        
        def dfs(row, col): 
            if board[row][col] == 'M':
                board[row][col] = 'X'
                
            else:
                
                count = 0
                for dirs in DIR:
                    dx, dy = row + dirs[0], col + dirs[1]
                    if inbound(dx,dy) and board[dx][dy] == 'M':
                        count += 1
                        
                if count:
                    board[row][col] = str(count)
                else:
                    board[row][col] = 'B'
                    for dirs in DIR:
                        dx, dy = row + dirs[0], col + dirs[1]
                        if inbound(dx,dy) and board[dx][dy] in ['M', 'E']:
                            dfs(dx,dy)
                        
                        
        inbound = lambda x, y: 0<= x < n and 0 <= y < m
        DIR = [[1,0],[0,1],[-1,0],[0,-1],[1,-1],[-1,1],[1,1],[-1,-1]]
        
        x,y = click[0], click[1]
        dfs(x,y)
        
        return board