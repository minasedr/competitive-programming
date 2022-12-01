class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        set<char> vow{'a', 'e', 'i', 'o','u'};
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            cnt[i] = (i ? cnt[i - 1]: 0);
            if (vow.count(tolower(s[i])))
                cnt[i]++;
        }
        return cnt[n / 2 - 1] * 1.0 == cnt[n - 1] / 2.0; 
    }
};