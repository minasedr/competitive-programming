class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int n = nums.size(), form = 0;
        long long ans = 0;
        
        for (int end = 0, start = 0; end < n; end++) {
            form += cnt[nums[end]]++;
            while (form >= k) {
                ans += (n - end);
                form -= --cnt[nums[start++]];
            }
        }
        
        return ans;
    }
};