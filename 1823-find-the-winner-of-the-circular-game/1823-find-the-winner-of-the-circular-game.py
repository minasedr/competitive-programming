class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        count = k
        q = deque([i for i in range(1, n+1)])
        if len(q) == 1: return q[0]
        while q:
            count = k
            cur = q.popleft()
            for _ in range(k-1):
                q.append(cur)
                cur = q.popleft()
            if len(q) == 1:
                return q[0]
        