class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        auto f = [&](int x) {
            int cnt = 0, beg = 0, end = 0;
            while (beg < n || end < n) {
                while (end < n && nums[end] - nums[beg] <= x)
                    end++;
                cnt += end - beg - 1;
                beg++;
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