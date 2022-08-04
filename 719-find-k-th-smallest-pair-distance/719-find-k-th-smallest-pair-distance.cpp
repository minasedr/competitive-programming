class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        auto f = [&](int x) {
            int cnt = 0;
            for (int i = 0 ; i < n; i++) {
                auto it = upper_bound(nums.begin() + i, nums.end(), nums[i] + x);
                int j = it - nums.begin() - i - 1;
                cnt += j;
            }
            return cnt >= k;
        };
        int lo = 0, hi = 1e6;
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