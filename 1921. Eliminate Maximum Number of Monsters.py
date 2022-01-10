class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        minAway = []
        for i in range(len(dist)):
            minAway.append(dist[i]/speed[i])
        minAway.sort()
        for j in range(len(minAway)):
            if minAway[j] <= j:
                return j
        return len(minAway)
