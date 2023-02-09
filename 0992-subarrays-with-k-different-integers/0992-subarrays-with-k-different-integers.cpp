class Solution {
public: 
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        function<int(int)> atMost;
        atMost = [&] (int x) {
            unordered_map<int, int> cnt;
            int ans = 0, beg = 0;
            for (int end = 0; end < n; end++) {
                cnt[nums[end]]++;
                while (cnt.size() > x) {
                    if (--cnt[nums[beg]] == 0)
                        cnt.erase(nums[beg]);
                    beg++;
                }
                ans += (end - beg + 1);
            }
            return ans;
        };
        
        return atMost(k) - atMost(k - 1);        
    }
};