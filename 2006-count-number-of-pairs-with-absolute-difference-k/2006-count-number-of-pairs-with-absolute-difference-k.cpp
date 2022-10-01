class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // nums[i] = nums[j] + k or nums[j] = nums[i] + k
        /*
            by re-arranging, we get
            nums[i] = nums[j] + k or nums[i] = nums[j] - k
            nums[i] = nums[j] +- k
        */
        unordered_map<int,int> mp;
        int cnt = 0;
        
        for (auto n: nums) {
            cnt += mp[n + k] + mp[n - k];
            mp[n]++;
        }
        return cnt;
    }
};