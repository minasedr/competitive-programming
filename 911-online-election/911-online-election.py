class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        self.persons, self.times = persons, times
        self.cand, self.result = defaultdict(int), [(0,0,0)]
        
        for i, x in enumerate(self.persons):
            self.cand[x] += 1
            
            if self.result[-1][2] > self.cand[x]:
                self.result.append((self.times[i], self.result[-1][1], self.result[-1][2]))
            else:
                self.result.append((self.times[i], x, self.cand[x]))
                
    def q(self, t: int) -> int:
            left, right = 0, len(self.times) - 1
            
            while (left <= right):
                mid = (left + right) // 2
                if self.times[mid] > t:
                    right = mid - 1
                else:
                    idx = mid
                    left = mid + 1
                    
            return self.result[idx+1][1]

# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)