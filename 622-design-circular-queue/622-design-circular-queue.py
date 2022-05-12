class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [-1] * k
        self.front = self.rear = -1
        self.k = k
        
    def enQueue(self, value: int) -> bool:
        if self.isFull(): return False
        elif self.isEmpty():
            self.front = self.rear = 0
            self.q[self.rear] = value
        else:
            self.rear = (self.rear + 1) % self.k
            self.q[self.rear] = value
        return True

    def deQueue(self) -> bool:
        if self.isEmpty(): return False
        elif self.front == self.rear:
            self.q[self.front] = -1
            self.front = self.rear = -1
        else:
            self.q[self.front] = -1
            self.front = (self.front + 1) % self.k
        return True
    def Front(self) -> int:
        return self.q[self.front]

    def Rear(self) -> int:
        return self.q[self.rear]

    def isEmpty(self) -> bool:
        return self.front == -1

    def isFull(self) -> bool:
        return (((self.rear + 1) % self.k) == self.front)


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()