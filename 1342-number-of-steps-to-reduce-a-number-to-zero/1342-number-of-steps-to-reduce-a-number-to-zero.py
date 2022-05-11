class Solution:
    def numberOfSteps(self, num: int) -> int:
        tot = 0
        if num == 0:
            return 0
        return 1 + (self.numberOfSteps(num-1) if num%2 else self.numberOfSteps(num//2))