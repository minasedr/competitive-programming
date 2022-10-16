class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size(), cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (i == k - 1)
                ans += (cur / k >= threshold);
            if (i >= k) {
                cur -= nums[i - k];
                ans += (cur / k >= threshold);
            }
        }
        return ans;
    }
};