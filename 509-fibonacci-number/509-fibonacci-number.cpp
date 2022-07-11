class Solution {
public:
    map<int,int>cache;
    int fib(int n) {
        if (n < 2)
            return n;
        if (cache[n])
            return cache[n];
        cache[n] = fib(n-1) + fib(n-2);
        return cache[n];
    }
};