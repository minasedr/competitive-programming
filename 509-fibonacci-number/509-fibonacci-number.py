class Solution:
    def fib(self, n: int, memo={}) -> int:
        if n in memo:
            return memo[n]
        if n < 2:
            return n
        result = self.fib(n-1, memo) + self.fib(n-2, memo)
        return result