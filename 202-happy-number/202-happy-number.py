class Solution:
    def isHappy(self, n: int) -> bool:
        visited, r = set(), 0
        
        for _ in range(n):
            while n:
                r, n = r+(n%10)**2, n//10  
            if r in visited: return False
            if r == 1: return True
            visited.add(r)
            n, r = r, 0

        return False