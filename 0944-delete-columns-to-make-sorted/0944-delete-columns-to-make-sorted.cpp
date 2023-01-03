class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        
        for (int i = 0; i < strs[0].size(); i++) {
            char prev = strs[0][i];
            bool ok = false;
            for (string st: strs) {
                if (prev > st[i])
                    ok = true;
                prev = max(prev, st[i]);
            }
            cnt += ok;
        }
        return cnt;
    }
};