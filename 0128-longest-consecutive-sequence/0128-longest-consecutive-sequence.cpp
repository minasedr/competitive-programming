class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto x: nums) {
            cnt[x] = cnt[x - 1] + 1;
            ans = max(ans, cnt[x]);
        }
        return ans;
    }
};