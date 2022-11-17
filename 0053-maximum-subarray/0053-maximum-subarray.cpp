class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0], cur = 0;
        for (auto n: nums) {
            cur = max(cur + n, n);
            max_sum = max(max_sum, cur);
        }
        return max_sum;
    }
};