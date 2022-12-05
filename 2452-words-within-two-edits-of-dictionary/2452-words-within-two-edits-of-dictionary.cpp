class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        function<bool(string, string)> check;
        check = [&](string a, string b) {
            int n = a.size(), d = 0;
            for (int i = 0; i < n; i++)
                if (a[i] != b[i])
                    d++;
            return (d <= 2 ? true: false);
        };
        vector<string> ans;

        unordered_set<string> cur;
        for (auto q: queries) {
            for (auto d: dictionary) {
                if (check(q, d)) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};