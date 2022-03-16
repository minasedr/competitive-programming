class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        number = 0
        
        for row in grid:
            left, right, fir = 0, len(row) - 1, len(row)
            while left <= right:
                mid = (left + right) // 2
                if row[mid] >= 0:
                    left = mid + 1
                else:
                    fir, right = mid, mid - 1
            number += abs(len(row) - fir)
            
        return number