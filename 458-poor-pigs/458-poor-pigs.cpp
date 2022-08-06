class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        auto f = [&](int x) {
            int T = (minutesToTest/minutesToDie);
            return pow((T + 1), x) >= buckets;
        };
        int lo = 0, hi = buckets;
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