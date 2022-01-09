class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def convertToMin(string):
            hour, minute = string.split(":")
            return int(hour) * 60  + int(minute)
        
        def calculateInterval(str1, str2):
            diff = abs(str2 - str1)
            return min(diff, 1440-diff)
        
        for time in range(len(timePoints)):
            timePoints[time] = convertToMin(timePoints[time])
        timePoints.sort()
        
        diff = calculateInterval(timePoints[-1], timePoints[0])
        for i in range(len(timePoints)-1):
            diff = min(diff, calculateInterval(timePoints[i+1], timePoints[i]))
        
        return diff
