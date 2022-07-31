class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = INT_MAX, hi = 0, n = nums.size();
        for (auto x: nums) {
            lo = min(lo, x);
            hi += x;
        }
        auto f = [&](int x) {
          int cur = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] > x)
                    return false;
                if (nums[i] + cur > x) {
                    cur = 0;
                    cnt++;
                }
                cur += nums[i];
            }
            cnt += (cur > 0);
            return cnt <= m;
        };
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (f(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
        
    }
};