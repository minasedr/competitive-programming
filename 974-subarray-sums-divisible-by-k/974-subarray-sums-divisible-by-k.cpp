class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> cnt{{0, 1}};
        int ans = 0, cur = 0;
        
        for (auto n: nums) {
            cur = (cur + n % k + k) % k;
            ans += cnt[cur]++;
        }
        return ans;
    }
};