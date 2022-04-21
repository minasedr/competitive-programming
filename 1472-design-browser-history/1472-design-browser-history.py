class Page:
    def __init__(self, url=None, prev=None, next=None):
        self.url = url
        self.prev = prev
        self.next = next
        
class BrowserHistory:
    def __init__(self, homepage: str):
        self.head, self.tail = Page(), Page()
        self.home = Page(homepage, self.head, self.tail)
        self.head.next = self.home
        self.tail.prev = self.home
        self.cur = self.home
        
    def visit(self, url: str) -> None:
        new = Page(url, self.cur, self.tail)
        self.cur.next = new
        self.tail.prev = new
        self.cur = self.cur.next
        
    def back(self, steps: int) -> str:
        for _ in range(steps):
            self.cur = self.cur.prev
            if self.cur == self.head:
                self.cur = self.head.next
                break
        return self.cur.url

    def forward(self, steps: int) -> str:
        for _ in range(steps):
            self.cur = self.cur.next
            if self.cur == self.tail:
                self.cur = self.tail.prev
                break
        return self.cur.url
    
# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)