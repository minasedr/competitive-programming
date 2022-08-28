class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m * k > bloomDay.size())
            return -1;
        
        function<bool(int)> isPos = [&] (int numDays) {
            int buoquets = 0, cnt = 0;
            for (auto bloom: bloomDay) {
                if (bloom > numDays) {
                    cnt = 0;
                    continue;
                }
                if (bloom <= numDays)
                    cnt++;
                if (cnt == k) {
                    buoquets++;
                    cnt = 0;
                }
            }
            return buoquets >= m;
        };
        
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (isPos(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};