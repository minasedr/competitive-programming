class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n + 1), suff(n + 1);
    
        for (int i = 1;  i <= n; i++)
            pref[i] = pref[i - 1] + nums[i - 1];
        
        for (int i = n - 2; i >= 0; i--)
            suff[i] = suff[i + 1] + nums[i + 1];

        for (int i = 0; i < n; i++)
            if (pref[i] == suff[i])
                return i;
       
        return -1;
    }
};