class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        function<bool(int)> f= [&] (long long x) {
            long long cnt = 0;
            for (int i = 0; i < piles.size(); i++)
                cnt += ceil((double)piles[i] / x);
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