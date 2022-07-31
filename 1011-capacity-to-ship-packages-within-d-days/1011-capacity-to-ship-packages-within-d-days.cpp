class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto f = [&](int x) {
            int cur = 0, cnt = 0;
            for (int i = 0; i < (int)weights.size(); i++) {
                if (weights[i] > x)
                    return false;
                if (cur + weights[i] > x) {
                    cur = 0;
                    cnt++;
                }
                cur += weights[i];
            }
            cnt += (cur > 0);
            return cnt <= days;
        };
        
        int lo = 0, hi = 0;
        for (auto x: weights)
            hi += x;
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