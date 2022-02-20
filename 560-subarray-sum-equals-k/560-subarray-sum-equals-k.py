class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        counter = prefix = 0
        n = len(nums)
        store = defaultdict(int)
        store[0] = 1
        for num in nums:
            prefix += num
            if prefix-k in store:
                counter += store[prefix-k]
            store[prefix] += 1
            
        return counter