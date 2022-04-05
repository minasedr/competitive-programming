class Solution:
    def climbStairs(self, n: int) -> int:
        prev, curr = 1, 2
        for i in range(2,n+1):
            curr = curr + prev
            prev = curr - prev
        return prev