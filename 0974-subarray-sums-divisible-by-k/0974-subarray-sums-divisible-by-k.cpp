class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), cur = 0;
        map<int, int> cnt{{0, 1}};
        
        for (int i = 0; i < n; i++) {
            cur = ((cur += nums[i]) % k + k) % k;            
            ans += cnt[cur]++;
        }
        return ans;
    }
};