class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    void dfs(int idx, vector<int>& nums) {
        if (cur.size() > 1)
            res.push_back(cur);
        unordered_set<int> vis;
        for (int i = idx; i < nums.size(); i++) {
            if (vis.count(nums[i]))
                continue;
            if (cur.empty() || cur.back() <= nums[i]) {
                cur.push_back(nums[i]);
                vis.insert(nums[i]);
                dfs(i + 1, nums);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        dfs(0, nums);
        return res;
    }
};
