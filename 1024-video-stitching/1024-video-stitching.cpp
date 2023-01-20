class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        sort(clips.begin(), clips.end());
        
        if (clips[0][0] > 0) return -1;
        vector<vector<int>> dp(105, vector<int>(105, -1));
        
        function<int(int, int)> dfs;
        dfs = [&](int i, int prev) {
            if (prev >= time)  return 0;
            if (i >= n) return (int)1e5;
            if (dp[i][prev] != -1)
                return dp[i][prev];
            int take = 1e5, dont = 0;
            if (prev >= clips[i][0])
                take = 1 + dfs(i + 1, max(prev, clips[i][1]));
            dont = dfs(i + 1, prev);
            
            return dp[i][prev] = min(take, dont);
        };
        
        int ans = dfs(0, clips[0][0]);
        
        return (ans >= 1e5 ? -1: ans);
    }
};