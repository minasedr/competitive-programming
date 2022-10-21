const int MOD = INT_MAX;
using i64 = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        i64 n = nums.size();
        i64 minPos, maxPos, start, ans;
        start = ans = 0;
        minPos = maxPos = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == minK)
                minPos = i;
            if (nums[i] == maxK)
                maxPos = i;
            if (nums[i] > maxK || nums[i] < minK)
                start = i + 1;
            ans += (max(0ll, (min(minPos, maxPos) - start + 1))) % MOD;
        }
        return ans;
    }
};