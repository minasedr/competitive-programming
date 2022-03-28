class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates) == 2: return True
        c, n = coordinates, len(coordinates)
        slopex = c[1][0]-c[0][0]
        slopey = c[1][1]-c[0][1]

        for i in range(n):
            dx = c[i][0]-c[0][0]
            dy = c[i][1]-c[0][1]
            if slopex * dy != slopey * dx:
                return False
            
        return True