class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> cnt;
        for (auto x: arr)
            cnt[x]++;
        vector<int> cur;
        for (auto [k , v]: cnt)
            cur.push_back(v);
        set<int> st(cur.begin(), cur.end());
        return st.size() == cur.size();
    }
};