class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        visited = set() 
        
        def dfs(r, c):
            visited.add((r,c))
            for d in DIR:
                dx, dy = r + d[0], c + d[1]
                if inbound(dx,dy) and (dx,dy) not in visited and board[dx][dy] == 'X':
                    dfs(dx,dy)
            return 1
        
        N, M, ans = len(board), len(board[0]), 0
        inbound = lambda x, y: 0 <= x < N and 0 <= y < M
        DIR = [(1,0), (0,1), (-1,0), (0,-1)]
        
        for i in range(N):
            for j in range(M):
                if (i,j) not in visited and board[i][j] == 'X':
                    ans += dfs(i,j)
        return ans