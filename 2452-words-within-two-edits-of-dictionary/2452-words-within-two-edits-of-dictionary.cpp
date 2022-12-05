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
        unordered_set<string> cur;
        for (auto q: queries) {
            for (auto d: dictionary) {
                if (check(q, d))
                    cur.insert(q);
            }
        }
        vector<string> ans;
        for (auto q: queries)
            if (cur.count(q))
                ans.push_back(q);
        
        return ans;
    }
};