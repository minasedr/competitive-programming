class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> vis;
        int n = s.size(), start = 0, ans = 0;
        
        for (int end = 0; end < n; end++) {
            while (vis.count(s[end])) {
                vis.erase(s[start]);
                start++;
            }
            vis.insert(s[end]);
            ans = max(ans, (int)vis.size());
        }
        return ans;
    }
};