class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> dpf(n, 1), dpb(n, 1);
        
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    dpf[i] = max(dpf[i], dpf[j] + 1);
        
        reverse(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    dpb[i] = max(dpb[i], dpb[j] + 1);
            
        reverse(dpb.begin(), dpb.end());
        for (int i = 0; i < n; i++)
            if (dpf[i] > 1 && dpb[i] > 1)
                ans = max(ans, dpf[i] + dpb[i] - 1);
        
        return n - ans;
    }
};