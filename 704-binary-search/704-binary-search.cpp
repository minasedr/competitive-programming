class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end())
            return -1;
        else {
            if (nums[it - nums.begin()] == target)
                return it - nums.begin();
            else
                return -1;
        }
    }
};