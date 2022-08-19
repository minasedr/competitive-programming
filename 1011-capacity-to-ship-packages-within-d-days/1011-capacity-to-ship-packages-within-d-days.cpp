class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        function<bool(int)> f = [&] (long long x) {
            int cur = 0, cnt = 0;
            for (int i = 0; i < weights.size(); i++) {
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
        
       long long lo = 0, hi = accumulate(weights.begin(), weights.end(), 0ll);
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