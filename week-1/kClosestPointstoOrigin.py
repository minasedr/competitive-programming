class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        import math
        def distance(point):
            [x,y] = point
            return (math.sqrt(x**2+y**2))
        
        sortedList = sorted(points, key=distance)
        return sortedList[:k]
