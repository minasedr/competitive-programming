class Solution {
public:
    bool match(string s, string t) {
        map<char,char> m1, m2;
        for (int i = 0; i < s.size(); i++) {
            if (!m1.count(s[i]))
                m1[s[i]] = t[i];
            if (!m2.count(t[i]))
                m2[t[i]] = s[i];
            if (m1[s[i]] != t[i] || m2[t[i]] != s[i])
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for (auto x: words) {
            if (match(x,pattern))
                res.push_back(x);
        }
        return res;
    }
};