class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), start = 0;
        int cur = 0, len = INT_MAX;
        
        for (int end = 0; end < n; end++) {
            cur += nums[end];
            while (cur - nums[start] >= target) {
                cur -= nums[start];
                start++;
            }
            if (cur >= target)
                len = min(len, end - start + 1);
        }
        return (len == INT_MAX? 0: len);
    }
};