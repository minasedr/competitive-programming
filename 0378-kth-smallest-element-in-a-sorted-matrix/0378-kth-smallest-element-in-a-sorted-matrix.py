class Solution:
    
    def ok(self, matrix, mid, k) -> bool:

        count = 0
        for row in matrix:
            count += bisect_right(row, mid)

        return count >= k
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
            
        lo, hi = -10**9, 10**9

        while lo < hi:

            mid = (lo + hi) // 2

            # number of elements less than or equal to mid >= k
            # if the number exists in the matrix

            if self.ok(matrix, mid, k):
                hi = mid
            else:
                lo = mid + 1

        return hi
    
        