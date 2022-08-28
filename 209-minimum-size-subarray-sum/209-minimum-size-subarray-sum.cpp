class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, beg = 0, cur = 0, n = nums.size();
        
        for (int end = 0; end < n; end++) {
            cur += nums[end];
            while (cur - nums[beg] >= target) {
                cur -= nums[beg];
                beg++;
            }
            if (cur >= target)
                ans = min(ans, end - beg + 1);
        }
        return (ans == INT_MAX ? 0: ans);
    }
};