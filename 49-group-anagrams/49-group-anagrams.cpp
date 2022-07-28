class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> group;
        for (auto x: strs) {
            string s = x;
            sort(s.begin(),s.end());
            group[s].push_back(x);
        }
        vector<vector<string>>res;
        for (auto p: group)
            res.push_back(p.second);
        return res;
    }
};