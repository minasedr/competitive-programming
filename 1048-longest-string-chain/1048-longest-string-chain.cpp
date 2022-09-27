class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), mx = 0;
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.size() < b.size();
        });
        
        for (auto word: words) {
            for (int j = 0; j < word.size(); j++) {
                string w = word.substr(0, j) + word.substr(j + 1);
                if (dp.count(w))
                    dp[word] = max(dp[word], dp[w] + 1);
                mx = max(mx, dp[word]);
            }
        }
        return mx + 1;
    }
};