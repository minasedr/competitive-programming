class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n + 1);
        
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (nums[i - 1] == 0);
        }
        
        int start = 0, ans = 0;
        for (int end = 1; end <= n; end++) {
            while (pref[end] - pref[start] > k)
                start++;
            ans = max(ans, end - start);
        }
        return ans;
    }
};