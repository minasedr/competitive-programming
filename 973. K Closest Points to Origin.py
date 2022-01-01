class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def distance(z):
            [x,y] = z
            return x ** 2 + y ** 2
        points.sort(key=distance)
        return points[:k]
