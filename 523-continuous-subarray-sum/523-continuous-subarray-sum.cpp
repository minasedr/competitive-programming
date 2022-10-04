class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt{{0, -1}};
        int ans = 0, cur = 0, n = nums.size();
        // 2, 0, 3
        for (int i = 0; i < n; i++) {
            (cur += nums[i]) %= k;
            if (cnt.count(cur))
                ans += (i - cnt[cur] > 1);
            else
                cnt[cur] = i;
        }
        return ans == 0 ? false: true;
    }
};