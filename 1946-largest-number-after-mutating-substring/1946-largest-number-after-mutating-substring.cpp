class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        bool ok = false;
        
        for (int i = 0; i < n; i++) {
            int x = num[i] - '0';
            if (x <= change[x]) {
                num[i] = char(change[x] + '0');
                if (x < change[x])
                    ok = true;
            }
            else if (ok)
                break;
        }
        return num;
    }
};