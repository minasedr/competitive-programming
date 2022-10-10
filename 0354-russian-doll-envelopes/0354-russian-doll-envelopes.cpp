class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
            // return (a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]);
        });
        vector<int> dp;
        int n = envelopes.size();
        
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if (it == dp.end())
                dp.push_back(envelopes[i][1]);
            else
                *it = envelopes[i][1];
        }
        return dp.size();
    }
};
/*
sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> dp;
        for (auto& env : envelopes) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
*/