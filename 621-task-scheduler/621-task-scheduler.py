class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count, counter = Counter(tasks), 0
        freqs = [x for x in count.values()]
        mode = max(freqs)
        left = (mode-1) * (n + 1)
        
        for i in freqs:
            if i == mode:
                counter += 1
        
        return max(left + counter, len(tasks))