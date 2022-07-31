class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto f = [&](int x) {
            int cur = 0;
            for (int i = 0; i < (int) nums.size(); i++) {
                cur += ceil((double) nums[i] / x);
            }
            return cur <= threshold;
        };
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
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