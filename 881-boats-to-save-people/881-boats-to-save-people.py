class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        l, r, counter = 0, len(people) - 1, 0

        while l <= r:
            if people[r] + people[l] <= limit:
                l += 1
            r -= 1
            counter += 1
        return counter