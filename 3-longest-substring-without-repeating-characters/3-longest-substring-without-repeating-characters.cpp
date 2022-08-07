class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        unordered_set<char> st;
        int beg = 0, end = 0;
        while (end < n) {
            if (st.count(s[end])) {
                st.erase(s[beg]);
                beg++;
            } else {
                st.insert(s[end]);
                ans = max(ans, (int)st.size());
                end++;
            }
        }
        return ans;
    }
};