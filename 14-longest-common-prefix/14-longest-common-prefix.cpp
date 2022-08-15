class Solution {
public:
    string prefix(string a, string b) {
        string res = "";
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            if (a[i] != b[i])
                break;
            res += a[i];
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];
        for (int i = 0; i < n; i++) {
            ans = prefix(ans, strs[i]);
        }
        return ans;
    }
};