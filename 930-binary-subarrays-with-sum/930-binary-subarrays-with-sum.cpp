class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0, cur = 0;
        unordered_map<int,int> cnt{{0, 1}};
        
        for (auto n: nums) {
            cur += n;
            ans += cnt[cur - goal];
            cnt[cur]++;
        }
        return ans;
    }
};