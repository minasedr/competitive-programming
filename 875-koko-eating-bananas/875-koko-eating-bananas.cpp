class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();
        auto f = [&](int k) {
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += ceil((double)piles[i] / k);
            }
            return cnt <= h;
        };
        long long lo = 1, hi = accumulate(piles.begin(), piles.end(), 0ll);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (f(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};