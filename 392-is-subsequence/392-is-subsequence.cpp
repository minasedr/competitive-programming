class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0, n = s.size(), m = t.size();
        if (m < n) return false;
        
        for (int i = 0; i < m; i++) {
            if (s[idx] == t[i])
                idx++;
        }
        return idx == n;
    }
};