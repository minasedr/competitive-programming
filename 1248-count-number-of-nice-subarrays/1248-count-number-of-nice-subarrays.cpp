class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>pref{{0,1}};
        int ans = 0, odds = 0;
        for (int i = 0; i < n; i++) {
            odds += (nums[i]% 2 == 1);
            ans += pref[odds - k];
            pref[odds]++;
        }
        return ans;
    }
};
