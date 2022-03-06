class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        heap = [(-fr,num) for num, fr in freq.items()]
        heapq.heapify(heap)
        ans = [heapq.heappop(heap)[1] for _ in range(k)]
        return ans