class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ss = s.size(), pp = p.size();
        
        if (pp > ss)
            return {};
        unordered_map<char,int> scnt, pcnt;
        
        for (int i = 0; i < pp; i++) {
            scnt[s[i]]++;
            pcnt[p[i]]++;
        }
        
        vector<int>res;
        if (scnt == pcnt)
            res.push_back(0);

        int beg = 0;
        for (int i = pp; i < ss; i++) {
            scnt[s[i]]++;
            scnt[s[beg]]--;
            
            if (scnt[s[beg]] == 0)
                scnt.erase(s[beg]);
            beg++;
            if (scnt == pcnt)
                res.push_back(beg);
        }
        return res;
    }
};