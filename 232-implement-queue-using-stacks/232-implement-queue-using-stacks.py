class MyQueue:

    def __init__(self):
        self.size = 0
        self.stack = []
        
    def push(self, x: int) -> None:
        self.stack = [x] + self.stack
        self.size += 1

    def pop(self) -> int:
        self.size -=1
        return self.stack.pop()

    def peek(self) -> int:
        return self.stack[-1] if self.stack else None

    def empty(self) -> bool:
        return self.size == 0

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()