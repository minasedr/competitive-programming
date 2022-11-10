class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i < k - 1)
                continue;
            if (i >= k)
                sum -= nums[i - k];
            ans = max(ans, sum / k);
        }
        return ans;
    }
};