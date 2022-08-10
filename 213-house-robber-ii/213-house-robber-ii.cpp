class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n), dp2(n);
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n - 1; i++)
            dp1[i] = nums[i] + max((i > 1 ? dp1[i - 2]: 0), (i > 2 ? dp1[i - 3]: 0));
        for (int i = 1; i < n; i++)
            dp2[i] = nums[i] + max((i > 1 ? dp2[i - 2]: 0), (i > 2 ? dp2[i -3]: 0));
        return max(*max_element(dp1.begin(), dp1.end()), *max_element(dp2.begin(), dp2.end()));
    }
};