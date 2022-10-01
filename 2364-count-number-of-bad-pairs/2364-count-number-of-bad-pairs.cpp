class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // nums[i] - i != nums[j] - j bad
        // nums[i] - i == nums[j] - j good
        // 0,1,2,3   n    0 + 1 + 2 + ... n - 1  = n (n - 1) / 2
        unordered_map<int,int> mp;
        long long cnt = 0, n = nums.size();
        
        for (int i = 0; i < n; i++)  {
            int diff = nums[i] - i;
            cnt += mp[diff]++;
        }
        return (long long) n * (n - 1) / 2 - cnt;
    }
};