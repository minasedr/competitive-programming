class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, minDiff = INT_MAX;
        
        vector<long> pref(n + 1), suff(n + 1);
        
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + nums[i - 1];
        
        for (int i = n - 1; i >= 0; i--)
            suff[i] = suff[i + 1] + nums[i];
        
        for (int i = 1; i <= n; ++i) {
            long left = pref[i] / i;

            long right = suff[i];
            if (i != n)
                right /= (n - i);
            
            int diff = abs(left - right);
            if (diff < minDiff) {
                minDiff = diff;
                ans = i;
            }
        }

        return ans - 1;
    }
};