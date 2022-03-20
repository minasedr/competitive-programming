class Solution:
    def divisorGame(self, n: int) -> bool:
        win = 1
        for i in range(n, 0, -1):
            if not (n % i): n -= i
            win = 1 if win == -1 else -1
        return win == 1