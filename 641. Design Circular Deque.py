class MyCircularDeque:

    def __init__(self, k: int):
        self._deque = [None] * k
        self._size = 0
        self._front = 0
    
    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        self._front = (self._front - 1) % len(self._deque)
        self._deque[self._front] = value
        self._size += 1
        return True
    
    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        last = (self._front + self._size) % len(self._deque)
        self._deque[last] = value
        self._size += 1
        return True
    
    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self._deque[self._front] = None
        self._front = (self._front + 1) % len(self._deque)
        self._size -= 1
        return True
    
    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        last = (self._front + self._size - 1) % len(self._deque)
        self._deque[last] = None
        self._size -= 1
        return True
    
    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self._deque[self._front]
    
    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        last = (self._front + self._size - 1) % len(self._deque)
        return self._deque[last]
    
    def isEmpty(self) -> bool:
        return self._size == 0
    
    def isFull(self) -> bool:
        return self._size == len(self._deque)
    
# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
