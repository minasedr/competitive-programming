class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int n = arr.size(), cnt = 1;
        
        for (auto x: arr) {
            int diff = x - difference;
            if (dp.count(diff))
                dp[x] = dp[diff] + 1;
            else
                dp[x] = 1;
            cnt = max(cnt, dp[x]);
        }
        return cnt;
    }
};