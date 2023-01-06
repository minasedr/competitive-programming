class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 1) return 10;
        vector<int> dp(11, -1);
        function<int(int)> f;
        
        f = [&](int k) {
            int ans = 9;
            for (int i = 0, q = 9; i < k - 1 and q > 0; i++, q--)
                ans *= q;
            return ans;
        };
        
        int cnt = 0;
        for (int i = 2; i <= n; i++)
            cnt += f(i);
        return (cnt ? cnt + 10 : 1);
    }
};