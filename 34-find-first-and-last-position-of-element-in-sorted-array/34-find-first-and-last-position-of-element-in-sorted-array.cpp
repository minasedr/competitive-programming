class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itl = lower_bound(nums.begin(), nums.end(), target);
        auto itr = upper_bound(nums.begin(), nums.end(), target);
        if (itl == nums.end())
            return {-1, -1};
        int lo = itl - nums.begin();
        int hi = itr - nums.begin();
        if (lo > hi - 1) return {-1, -1};
        return {lo, hi - 1};
    }
};