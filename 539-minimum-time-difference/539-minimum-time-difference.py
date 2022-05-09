class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        change = lambda x: int(x[:2]) * 60 + int(x[3:])
        
        maxTime, inMins, res = 1440, [], math.inf
        
        for x in timePoints:
            add = change(x) % maxTime
            inMins.append(add)
           
        inMins.sort()
        for i in range(1, len(inMins)):
            res = min(res, inMins[i]-inMins[i-1])
            
        return min(res, maxTime-inMins[-1] + inMins[0])