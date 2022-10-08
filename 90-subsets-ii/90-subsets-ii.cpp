class Solution {
public:
    vector<vector<int>> res;
    set<multiset<int>> vis;
    vector<int> cur;
    void dfs(int idx, vector<int> &nums) {
        if (idx >= nums.size()) {
            multiset<int> st(cur.begin(), cur.end());
            if (!vis.count(st))
                res.push_back(cur);
            vis.insert(st);
            return;
        }
        cur.push_back(nums[idx]);
        dfs(idx + 1, nums);
        cur.pop_back();
        dfs(idx + 1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};