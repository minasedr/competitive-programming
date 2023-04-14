class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        function<int(int, int)> lps;
        lps = [&](int beg, int end) {
            if (beg >= end)
                return max(0, end - beg + 1);
            if (dp[beg][end] != -1)
                return dp[beg][end];
            if (s[beg] == s[end])
                dp[beg][end] = 2 + lps(beg + 1, end - 1);
            else
                dp[beg][end] = max(lps(beg + 1, end), lps(beg, end - 1));
            return dp[beg][end];
        };
        
        return lps(0, n - 1);
    }
};