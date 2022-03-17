class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        
        def possible(cap):
            total, day = cap, 1
            
            for i in weights:
                if total < i:
                    day, total = day+1, cap - i
                else:
                    total -= i
                    
            return True if day <= days else False
            
        left, right, ans = max(weights), sum(weights), 0
        
        while left <= right:
            mid = (left + right) // 2
            
            if possible(mid):
                ans, right = mid, mid - 1
            else:
                left = mid + 1
                    
        return ans