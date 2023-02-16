int dp[101][27][101][101];
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof dp);
        
        function<int(int, int, int, int)> dfs;
        dfs = [&](int i, int last, int len, int k) {
            if (k < 0)
                return (int)1e9;
            if (i >= n)
                return 0;
            if (dp[i][last][len][k] != -1)
                return dp[i][last][len][k];

            int take = dfs(i + 1, last, len, k - 1), dont = 0;
            
            if(s[i] - 'a' == last) {
                dont = (len == 1 || len == 9 || len == 99);
                dont += dfs(i+1, last, len+1, k);
            } else
                dont = 1 + dfs(i+1, s[i] - 'a', 1, k);

            return dp[i][last][len][k] = min(take, dont);
        };
        
        return dfs(0, 26, 0, k);
    }
};