class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        dfs(idx + 1, nums);
        cur.pop_back();
        dfs(idx + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};