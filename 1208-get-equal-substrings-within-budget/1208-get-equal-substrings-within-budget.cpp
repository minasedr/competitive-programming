class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0, start = 0;
        
        for (int end = 0; end < n; end++) {
            while (maxCost - abs(s[end] - t[end]) < 0) {
                maxCost += abs(s[start] - t[start]);
                start++;
            }
            maxCost -= abs(s[end] - t[end]);
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};