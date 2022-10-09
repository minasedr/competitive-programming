class Solution {
public:
    bool check(vector<int> a) {
        int n = a.size();
        for (int i = 1; i < n; i++)
            if (a[i] < a[i - 1])
                return false;
        return true;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        set<vector<int>> vis;
        for (int i = 0; i < (1 << n); i++) {
            vector<int>cur;
            for (int j = 0; j < 32; j++) {
                if (i & (1 << j))
                    cur.push_back(nums[j]);
            }
            if (vis.count(cur))
                continue;
            if (cur.size() >= 2 && check(cur))
                res.push_back(cur);
            vis.insert(cur);
        }
        return res;
    }
};