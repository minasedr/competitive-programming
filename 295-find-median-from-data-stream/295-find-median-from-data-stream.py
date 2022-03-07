class MedianFinder:
    def __init__(self):
        self.left_heap = []
        self.right_heap = []
        
    def addNum(self, num: int) -> None:
        heappush(self.left_heap, -num)
        heappush(self.right_heap, -heappop(self.left_heap))
        
        if len(self.right_heap) > len(self.left_heap):
            heappush(self.left_heap, -heappop(self.right_heap))

    def findMedian(self) -> float:
        if len(self.left_heap)  == len(self.right_heap):
            return (self.right_heap[0] + -self.left_heap[0]) / 2 
        else:
            return -self.left_heap[0]
    
# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()