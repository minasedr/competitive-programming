class Solution {
public:
    string cntsort(string s) {
        int cnt[26] = {};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        string t = "";
        for (int c = 0; c < 26; c++) {
            t += string(cnt[c], c + 'a');
        }
        return t;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> group;
        for (auto x: strs) {
            group[cntsort(x)].push_back(x);
        }
        vector<vector<string>>res;
        for (auto p: group)
            res.push_back(p.second);
        return res;
    }
};