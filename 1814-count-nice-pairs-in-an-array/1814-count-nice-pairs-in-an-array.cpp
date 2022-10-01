const int MOD = 1e9 + 7;
class Solution {
public:
    int rev(int num) {
        int ans = 0;
        while (num) {
            int r = num % 10;
            ans = (ans * 10) + r;
            num /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        // nums[i] - rev(nums[i]) == nums[j] - rev(nums[j]);
        int ans = 0;
        
        unordered_map<int, int> mp;
        for (auto n : nums) {
            int diff = n - rev(n);
            (ans += mp[diff]++) %= MOD;
        }
        return ans;
    }
};