class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        vector<int> dp(105, 105);
        dp[0] = 0;
        
        for (auto c: clips)
            for (int i = c[0] + 1; i <= c[1]; i++)
                dp[i] = min(dp[i], 1 + dp[c[0]]);
        
        return (dp[time] > 100 ? -1 : dp[time]);
    }
};