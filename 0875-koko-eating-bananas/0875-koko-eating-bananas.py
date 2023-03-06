class Solution:
    def checker(self, piles, h, mid):
        num = 0
        for pile in piles:
            num += ceil(pile / mid)
        return num <= h
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low = 0
        high = max(piles) 
        
        while low + 1 < high:
            mid = low + (high - low) // 2
            if self.checker(piles, h , mid):
                high = mid
            else:
                low = mid
        return high        