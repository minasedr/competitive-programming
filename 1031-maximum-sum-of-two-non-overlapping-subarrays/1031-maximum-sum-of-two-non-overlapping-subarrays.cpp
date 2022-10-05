class Solution {
public:
    int maxSum(vector<int>& nums, int L, int R) {
        int n = nums.size(), cur = 0;
        vector<int> pref(n), suff(n + 1);
        
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (i >= L) cur -= nums[i - L];
            pref[i] = max(i ? pref[i - 1] : 0, cur);
        }
        
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur += nums[i];
            if (i + R < n) cur -= nums[i + R];
            suff[i] =  cur;
        }
        
        int ans = 0;
        for (int i = L - 1; i <= n - R; i++)
            ans = max(ans, pref[i] + suff[i + 1]);
        
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(maxSum(nums, firstLen, secondLen), maxSum(nums, secondLen, firstLen));
    }
};