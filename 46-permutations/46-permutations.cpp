class Solution {
public:
    vector<vector<int>> res;
    void f(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            f(i + 1, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(0, nums);
        return res;
    }
};