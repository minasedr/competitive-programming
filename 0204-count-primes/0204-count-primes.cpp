const int N = 5 * 1e6 + 2;
class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[N];
        memset(isPrime, true, sizeof isPrime);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++)
            if (isPrime[i])
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
        return count(isPrime, isPrime + n, true);
    }
};