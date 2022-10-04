class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        int start = 0, maxCnt = 0;
        vector<int>cnt(26);
        
        for (int end = 0; end < n; end++) {
            maxCnt = max(maxCnt, ++cnt[s[end] - 'A']);
            while (end - start + 1 - maxCnt > k) {
                cnt[s[start] - 'A']--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};