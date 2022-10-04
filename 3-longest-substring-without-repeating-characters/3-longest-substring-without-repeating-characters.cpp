class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = 0, n = s.size();
        unordered_set<char> st;
        
        for (int end = 0; end < n; end++) {
            while (st.count(s[end])) {
                st.erase(s[start]);
                start++;
            }
            st.insert(s[end]);
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};