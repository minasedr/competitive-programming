class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto f = [&](int x) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int j = upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
                cnt += j;
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