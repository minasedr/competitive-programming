class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //  [1,2,3,4,5]
        int n = nums.size();
        vector<int> dp;
        
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end())
                dp.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return dp.size() >= 3;
        // [1, 2, 3]
    }
};