class Solution:
    def countOdds(self, low: int, high: int) -> int:
        count = 0
        num = (high - low + 1)
        if num % 2 == 0:
            return num//2
        else:
            if high % 2 == 0 and low % 2 == 0:
                return num//2
            else:
                return num//2 + 1