class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ans = []
        for x in matrix:
            ans += x
        
        left, right = 0, len(ans) - 1
        while left <= right:
            mid = (left + right) // 2
            if target < ans[mid]:
                right = mid - 1
            elif target > ans[mid]:
                left = mid + 1
            else:
                return True
        return False