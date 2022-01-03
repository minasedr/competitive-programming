class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = sorted(heights)
        counter = 0
        for l in range(len(heights)):
            if heights[l] != expected[l]:
                counter += 1
        return counter
