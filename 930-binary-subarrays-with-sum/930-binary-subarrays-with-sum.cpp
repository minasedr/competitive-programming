class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> cnt{{0, 1}};
        int ans = 0, cur = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            ans += cnt[cur - goal];
            cnt[cur]++;
        }
        return ans;
    }
};