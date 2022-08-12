class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        for (int i = 0; i < (int)nums.size(); i++) {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end())
                dp.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return dp.size();
    }
};