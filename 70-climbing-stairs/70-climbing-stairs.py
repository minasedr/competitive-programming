class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: return 1
        prev, curr = 1, 2
        for i in range(2,n):
            prev, curr = curr, prev + curr
        return curr