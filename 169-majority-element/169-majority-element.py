class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        store = defaultdict(int)
        for i in nums:
            store[i] += 1
            if store[i] > len(nums)//2: return i