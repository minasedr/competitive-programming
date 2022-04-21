class BrowserHistory:
    def __init__(self, homepage: str):
        self.q = [homepage]
        self.cur = 0
        
    def visit(self, url: str) -> None:
        self.q = self.q[:self.cur+1]
        self.q.append(url)
        self.cur += 1
        
    def back(self, steps: int) -> str:
        self.cur = max(self.cur-steps, 0)
        return self.q[self.cur]

    def forward(self, steps: int) -> str:
        self.cur = min(self.cur+steps, len(self.q)-1)
        return self.q[self.cur]

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)