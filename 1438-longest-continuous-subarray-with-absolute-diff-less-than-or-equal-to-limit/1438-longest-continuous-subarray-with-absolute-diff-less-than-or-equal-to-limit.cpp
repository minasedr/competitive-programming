class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int ans = 1, start = 0, n = nums.size();
        
        for (int end = 0; end < n; end++) {
            ms.insert(nums[end]);
            while (*ms.rbegin() - *ms.begin() > limit)
                ms.erase(ms.find(nums[start++]));
            
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};