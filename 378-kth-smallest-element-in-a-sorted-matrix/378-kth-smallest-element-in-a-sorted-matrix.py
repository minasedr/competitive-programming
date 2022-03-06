class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        rows, cols, d, heap = len(matrix), len(matrix[0]), [], []
        length = rows * cols
        
        for y in matrix:
            for x in y:
                heap.append(x)
                
        heapq.heapify(heap)
      
        for i in range(k-1):
            heapq.heappop(heap)
            
        return heap[0]