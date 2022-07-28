class Solution {
public:
    bool anagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        map<char,int>cnt;
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
    vector<string> removeAnagrams(vector<string>& words) {
        int beg = 0, end = 1, n = words.size();
        while (end < n) {
            while (end < n && anagram(words[beg], words[end])) {
                words[end] = "#";
                end++;
            }
            beg = end;
            end++;
        }
        vector<string>ans;
        for (auto x: words)
            if (x != "#")
                ans.push_back(x);
        return ans;
    }
};