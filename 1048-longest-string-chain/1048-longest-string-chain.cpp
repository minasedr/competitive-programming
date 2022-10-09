class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 0;
        sort(words.begin(), words.end(), [](string s, string t) {
            return s.size() < t.size();
        });
        unordered_map<string, int> dp;
        
        for (auto w: words) {
            dp[w] = 1;
            for (int j = 0; j < w.size(); j++) {
                string s = w.substr(0, j) + w.substr(j + 1);
                dp[w] = max(dp[w], dp[s] + 1);
            }
            ans = max(ans, dp[w]);
        }
        return ans;
    }
};