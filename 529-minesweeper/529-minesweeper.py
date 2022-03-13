class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        n, m = len(board), len(board[0])
        
        def dfs(row, col): 
            if board[row][col] == 'M':
                board[row][col] = 'X'
                
            else:
                count = 0
                for pt in DIR:
                    dx, dy = row + pt[0], col + pt[1]
                    if inbound(dx,dy) and board[dx][dy] == 'M':
                        count += 1
                        
                if count:
                    board[row][col] = str(count)
                else:
                    board[row][col] = 'B'
                    for pt in DIR:
                        dx, dy = row + pt[0], col + pt[1]
                        if inbound(dx,dy) and board[dx][dy] in ['M', 'E']:
                            dfs(dx,dy)
                            
            return board
                        
        inbound = lambda x, y: 0<= x < n and 0 <= y < m
        DIR = [[1,0],[0,1],[-1,0],[0,-1],[1,-1],[-1,1],[1,1],[-1,-1]]
        
        x,y = click[0], click[1]
        return dfs(x,y)