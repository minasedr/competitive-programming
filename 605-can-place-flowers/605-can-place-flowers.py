class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        f, m = flowerbed, len(flowerbed)
        
        for i in range(m):
            if f[i] == 0 and n:
                x = f[i-1] if i>0 else 0
                y = f[i+1] if i+1<m else 0
                if x == 0 and y == 0:
                    f[i], n = 1, n-1
                    
        return n == 0