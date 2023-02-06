class Solution:
    def racecar(self, target: int) -> int:
        Q = deque([(0, 1)])
        vis = set([(0, 1)])
        
        ans = 0
        while Q:
            for _ in range(len(Q)):
                pos, speed = Q.popleft()
                if pos == target:
                    return ans
                A = (pos + speed, speed * 2)
                R = (pos, -1 if speed > 0 else 1)
                if A not in vis and 0 <= A[0] <= 2 * target:
                    Q.append(A)
                    vis.add(A)
                if R not in vis:
                    Q.append(R)
                    vis.add(R)
            ans += 1
        
        return -1