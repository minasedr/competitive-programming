class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        set<string> ans;
        function<bool(string)> valid;
        valid = [&] (string cur) {
            if (cur.back() == '.')
                return false;
            if (count(cur.begin(), cur.end(), '.') != 3)
                return false;
            string y;
            for (auto x: cur) {
                if (x == '.') {
                    if (y.size() > 3 or stoi(y) > 255)
                        return false;
                    if (y.size() > 1 and y[0] == '0')
                        return false;
                    y = "";
                } else
                    y += x;                
            }
            if (y.size() > 1 and y[0] == '0')
                return false;
            if (y.size() > 3 or stoi(y) > 255)
                return false;
            return true;
        };
        
        function<void(int, string, string)> dfs;
        dfs = [&](int i, string cur, string put) {
            
            if (i >= n) {
                if (valid(put + cur))
                    ans.insert(put + cur);
                return;
            }
            if (cur.size() > 2 or count(put.begin(), put.end(), '.') > 3)
                return;
            dfs(i + 1, "", put + cur + s[i] + ".");
            dfs(i + 1, cur + s[i], put);
        };
        
        dfs(0, "", "");
        vector<string> res(ans.begin(), ans.end());
        
        return res;
    }
    
};