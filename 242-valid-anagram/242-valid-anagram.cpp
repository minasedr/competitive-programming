class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>cnt;
        if (s.size() != t.size())
            return false;
        for (auto x: s)
            cnt[x]++;
        for (auto y: t) {
            if (cnt[y])
                cnt[y]--;
            else
                return false;
        }
        return true;
    }
};