class Solution {
public:
    vector<vector<int>> res;
    void dp(int idx, int tar, int cur, vector<int> app, vector<int> nums) {
        if (cur >= tar) {
            if (cur == tar)
                res.push_back(app);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i  - 1])
                continue;
            app.push_back(nums[i]);
            dp(i + 1, tar ,cur + nums[i], app, nums);
            app.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>cur;
        dp(0, target, 0, cur, candidates);
        return res;
    }
};