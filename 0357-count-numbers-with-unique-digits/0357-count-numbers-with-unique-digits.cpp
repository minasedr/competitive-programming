class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int ans = 10, k = 9, tmp = 9;
        for (int i = 0; i < n - 1; i++) {
            tmp *= k--;
            ans += tmp;
        }
        return ans;
    }
};