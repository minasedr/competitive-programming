class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        set<char> vis1, vis2, vis3, vis4, vis5;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.' && vis1.count(board[i][j]))
                    return false;

                if (board[j][i] != '.' && vis2.count(board[j][i]))
                    return false;
                
                vis1.insert(board[i][j]);
                vis2.insert(board[j][i]);
            }
            vis1.clear();
            vis2.clear();
            for (int j = 0; j < 3; j++) {
                int a = j, b = j + 3, c = j + 6;
                if (board[i][a] != '.' && vis3.count(board[i][a]))
                    return false;
                
                if (board[i][b] != '.' && vis4.count(board[i][b]))
                    return false;
                
                if (board[i][c] != '.' && vis5.count(board[i][c]))
                    return false;
                
                vis3.insert(board[i][a]);
                vis4.insert(board[i][b]);
                vis5.insert(board[i][c]);
            }
            if (i % 3 == 2) {
                vis3.clear();
                vis4.clear();
                vis5.clear();
            }
        }
        return true;
    }
};