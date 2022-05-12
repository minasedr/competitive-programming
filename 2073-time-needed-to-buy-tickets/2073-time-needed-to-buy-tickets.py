class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        q = deque([(t,i) for i, t in enumerate(tickets)])
        time = 0
        while q:
            time += 1
            cur, idx = q.popleft()
            if cur - 1 == 0:
                if idx == k:
                    return time
            else:
                q.append((cur-1, idx))