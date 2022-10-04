class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // when update start 
        // k += (end - start) * abs(nums[start] - nums[start + 1])
        
        int start = 0, ans = 0, n = nums.size();
        sort(nums.begin(), nums.end(), greater<>());
        
        for (int end = 0; end < n; end++) {
            while (nums[start] - nums[end] > k) {
                k += (end - start - 1) * (nums[start] - nums[start + 1]);
                start++;
            }
            ans = max(ans, end - start + 1);
            k -= nums[start] - nums[end];
        }
        return ans;
    }
};