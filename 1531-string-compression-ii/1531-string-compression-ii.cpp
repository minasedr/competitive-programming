int dp[101][27][101][101];
class Solution {
public:
    string str;
    
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        str = s;
        memset(dp, -1, sizeof dp);
        
        function<int(int, int, int, int)> dfs;
        dfs = [&](int i, int prev, int len, int k) {
            if (k < 0)
                return (int)1e9;
            if (i >= n) return 0;
            if(dp[i][prev][len][k] != -1)
                return dp[i][prev][len][k];

            int del = dfs(i+1, prev, len, k-1);
            int keep = 0;
            if(s[i] - 'a' == prev) {
                if(len == 1 || len == 9 || len == 99) {
                    keep += 1;
                }
                keep = keep + dfs(i+1, prev, len+1, k);
            }
            else {
                keep = 1 + dfs(i+1, s[i] - 'a', 1, k);
            }

            return dp[i][prev][len][k] = min(del, keep);
        };
        
        return dfs(0, 26, 0, k);
    }
};