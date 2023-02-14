class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), bcnt = 0, ops = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                ops = min(ops + 1, bcnt);
            else
                bcnt++;
        }
        return ops;
    }
};