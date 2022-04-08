class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        fir, arrows = points[0], 1
        
        for i in range(len(points)):
            if fir[1] < points[i][0]:
                arrows += 1
                fir = points[i]
                
        return arrows