class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();
        auto f = [&](int k) {
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (piles[i] - 1) / k + 1;
            }
            return cnt <= h;
        };
        long long lo = 1, hi = *max_element(piles.begin(), piles.end());
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