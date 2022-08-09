/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, pair<int, vector<int>>> mp;
        for (auto e: employees) {
            mp[e->id].first = e->importance;
            for (auto x: e->subordinates) {
                mp[e->id].second.push_back(x);
            }
        }
        set<int>st;
        int cnt = 0;
        function<int(int)> dfs = [&](int root) {
            if (st.count(root))
                return 0;
            cnt += mp[root].first;
            for (auto x: mp[root].second) {
                dfs(x);
            }
            return cnt;
        };
        return dfs(id);
    }
};