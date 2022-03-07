class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = [-x for x in stones]
        heapify(heap)
        
        while len(heap) > 1:
            y = heappop(heap)
            x = heappop(heap)
            if x != y:
            # if x == y:
            #     x = y = 0
            # else:
                y -= x
                x = 0
                heappush(heap, y)
                
        return -heap[0] if heap else 0