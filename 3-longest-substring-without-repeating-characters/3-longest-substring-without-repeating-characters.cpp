class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), beg = 0, end = 0, ans = 0;
        set<char> st;
        
        while (end < n) {
            if (st.count(s[end]))
                st.erase(s[beg++]);
            else {
                st.insert(s[end++]);
                ans = max(ans, (int)st.size());
            }
        }
        return ans;
    }
};