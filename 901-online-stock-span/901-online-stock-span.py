class StockSpanner:

    def __init__(self):
        self.store = defaultdict(int)
        self.stack = []

    def next(self, price: int) -> int:
        inc = 0
        while self.stack and self.stack[-1] <= price:
            p = self.stack.pop()
            inc += self.store[p]
        self.store[price] = inc + 1
        self.stack.append(price)
        return self.store[price] or 1

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)