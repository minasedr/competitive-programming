class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        store, n = defaultdict(int), len(nums)
        
        for i in nums:
            store[i] += 1
            if store[i] > n//2: return i