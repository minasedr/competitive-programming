class Solution {
public:
    vector<int> res;
    void f(int n, int k, int cur, int prev) {
        if (n <= 0) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (abs(i - prev) == k)
                f(n - 1, k, cur * 10 + i, i);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++)
            f(n - 1, k, i, i);
        return res;
    }
};