# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right, first = 0, n, -1
        
        while left <= right:
            mid = (left + right) // 2
            if isBadVersion(mid):
                first, right = mid, mid - 1
            else:
                left = mid + 1
        return first