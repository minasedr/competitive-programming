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
        for (int i = words.size() - 1; i > 0; i--) {
            if (anagram(words[i], words[i-1]))
                words[i] = "#";
        }
       
        vector<string>ans;
        for (auto x: words)
            if (x != "#")
                ans.push_back(x);
        return ans;
    }
};