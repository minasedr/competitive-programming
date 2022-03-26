class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        ans, index = math.inf, -1
        
        for i in range(len(points)):
            pt = points[i]
            if pt[0] == x or pt[1] == y:
                dist = abs(pt[0]-x) + abs(pt[1]-y)
                if dist < ans: index = i
                ans = min(ans, dist)
            
        return index