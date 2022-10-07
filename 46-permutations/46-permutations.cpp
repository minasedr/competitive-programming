class Solution {
public:
    vector<vector<int>> res;
    set<int> vis;
    void f(int i, vector<int> cur, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int j = 0; j < nums.size(); j++) {
            if (!vis.count(nums[j])) {
                vis.insert(nums[j]);
                cur.push_back(nums[j]);
                f(i + 1, cur, nums);
                cur.pop_back();
                vis.erase(nums[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>cur;
        f(0, cur, nums);
        return res;
    }
};