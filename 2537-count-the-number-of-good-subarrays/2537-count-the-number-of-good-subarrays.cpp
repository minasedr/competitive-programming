class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int n = nums.size(), form = 0, start = 0;
        long long ans = 0;
        
        for (int end = 0; end < n; end++) {
            form += cnt[nums[end]];
            cnt[nums[end]]++;
            while (form >= k) {
                if (--cnt[nums[start]])
                    form -= cnt[nums[start]];
                if (not cnt[nums[start]])
                    cnt.erase(nums[start]);
                start++;
            }
            ans += start;
        }
        
        return ans;
    }
};