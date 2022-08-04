class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        auto f = [&](int a) {
            int x = 1, y = n, cnt = 0;
            while (y > 0 && x <= m) {
                if (x * y > a)
                    y--;
                else {
                    cnt += y;
                    x++;
                }
            }
            return cnt >= k;
        };
        
        int lo = 1, hi = m * n;
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