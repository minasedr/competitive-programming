class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, mid = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] > mid)
                return true;
            else if (nums[right] > left && nums[right] < mid)
                mid = nums[right];
            else if (nums[right] < left)
                left = nums[right];
        }
        return false;
    }
};