class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        k = n - k;
        int cur = 0, ans = sum;
        for (int i = 0; i < n; i++) {
            cur += cardPoints[i];
            if (i == k - 1)
                ans = min(ans, cur);
            if (i >= k) {
                cur -= cardPoints[i - k];
                ans = min(ans, cur);
            }
        }
        return sum - ans;
    }
};