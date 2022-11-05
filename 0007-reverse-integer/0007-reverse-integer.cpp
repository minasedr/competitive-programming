class Solution {
public:
    long long rev(long long n) {
        long long ans = 0;
        while (n) {
            ans = (ans * 10) + (n % 10);
            n /= 10;
        }
        return ans;
    }
    long long reverse(long long x) {
        if (x == 0) return 0;
        int n = log10(abs(x)) + 1;
        long long r = rev(abs(x));
        if (r > INT_MAX)
            return 0;
        long long ans = rev(abs(x));
        return (x < 0 ? -ans : ans);
    }
};