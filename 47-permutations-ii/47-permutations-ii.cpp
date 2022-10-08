using i64 = long long;
class Solution {
public:
    vector<vector<int>> res;
    set<vector<int>> vis;
    void dfs(int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            if (!vis.count(nums))
                res.push_back(nums);
            vis.insert(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            dfs(idx + 1, nums);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};