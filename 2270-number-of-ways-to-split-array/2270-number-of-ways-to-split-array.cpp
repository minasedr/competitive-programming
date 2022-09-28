class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        //nums[10, 4, -8, 7]
        // pref [10, 14, 6, 14]
        // suff [13, 3, -1, 7, 0]
        
        int n = nums.size();
        vector<long long>pref(n + 1), suff(n + 1);
        pref[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        
        for (int i = 1;  i < n; i++)
            pref[i] = pref[i - 1] + nums[i];
        
        for (int i = n - 2; i >= 0; i--)
            suff[i] = suff[i + 1] + nums[i];
        
        long long cnt = 0;
        for (int i = 0; i < n - 1; i++)
            if (pref[i] >= suff[i + 1])
                cnt++;
       
        return cnt;
    }
};