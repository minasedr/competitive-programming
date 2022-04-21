class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        N, M, ans = len(board), len(board[0]), 0

        for i in range(N):
            for j in range(M):
                if board[i][j] == 'X':
                    if (i > 0 and board[i-1][j] == 'X') or (j > 0 and board[i][j-1] == 'X'):
                        continue
                    ans += 1
                       
        return ans