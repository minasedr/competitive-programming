class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, start = 0, cur = 0;
        int n = nums.size();
        
        for (int end = 0; end < n; end++) {
            while (end < n && (cur & nums[end]))
                cur ^= nums[start++];
            cur |= nums[end];
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};