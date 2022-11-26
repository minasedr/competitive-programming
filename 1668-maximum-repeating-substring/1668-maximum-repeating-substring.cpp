class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int idx = i, cur = 0;
            while (idx < n) {
                if (sequence.substr(idx, m) == word)
                    cur++, idx += m;
                else
                    break;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};