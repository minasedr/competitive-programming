class Solution {
public:
    bool isPowerOfThree(double n) {
        if (n < 1) return false;
        if (n == 1) return true;
        return isPowerOfThree(n / 3);
    }
};