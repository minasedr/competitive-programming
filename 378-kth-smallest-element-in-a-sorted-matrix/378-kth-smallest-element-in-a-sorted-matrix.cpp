class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto f = [&](int x) {
            int cnt = 0, r = 0, c = n - 1;
            while (r < matrix.size() && c >= 0) {
                if (matrix[r][c] <= x)
                    cnt += (c + 1), r++;
                else c--;
            }
            return cnt >= k;
        };
        int lo = matrix[0][0], hi = matrix[n-1][n-1];
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