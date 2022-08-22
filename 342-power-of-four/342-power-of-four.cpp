class Solution {
public:
    bool isPowerOfFour(int n) {
        double N = n;
        while (N > 1)
            N /= 4;
        return N == 1;
    }
};