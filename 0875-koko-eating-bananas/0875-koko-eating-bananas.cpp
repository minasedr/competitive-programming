class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto valid = [&](int mid) {
            int cnt = 0;
            for (auto pile: piles)
                cnt += (pile + mid - 1) / mid;
            return cnt <= h;
        };
        
        int lo = 1, hi = 1e9;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (valid(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};