class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (cnt.count(nums[i]) && i - cnt[nums[i]] <= k)
                return true;
            cnt[nums[i]] = i;
        }
        return false;
    }
};