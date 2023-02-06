class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), cnt = 0;
        
        for (auto word: words)
            if (word.substr(0, n) == pref)
                cnt++;
        
        return cnt;
    }
};