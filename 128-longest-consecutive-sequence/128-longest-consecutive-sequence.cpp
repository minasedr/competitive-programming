class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        sort(nums.begin(), nums.end());
        for (auto x : nums)
            m[x] = 1;
            
        int ans = 0;
        for (auto x: nums) {
            m[x] = m[x-1] + 1;
            ans = max(ans, m[x]);
        }
        return ans;
    }
};