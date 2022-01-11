class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        return [value for i, value in enumerate(sorted(set(nums), key=lambda x: count[x], reverse=True)) if i < k]
