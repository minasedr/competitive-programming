class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string s, string t) {
            return s.size() < t.size();
        });
        map<string, int> dp;
        int mx = 1;
        for (auto word: words) {
            dp[word] = 1;
            for (int j = 0; j < word.size(); j++) {
                string s = word.substr(0, j) + word.substr(j + 1);
                if (dp.count(s)) {
                    dp[word] = max(dp[word], dp[s] + 1);
                    mx = max(mx ,dp[word]);
                }
            }
        }
        return mx;
    }
};