class MyHashSet:

    def __init__(self):
        self.hash = [math.inf] * (10 ** 6 + 1)
    def add(self, key: int) -> None:
        self.hash[key] = key

    def remove(self, key: int) -> None:
        if self.hash[key] != math.inf:
            self.hash[key] = math.inf

    def contains(self, key: int) -> bool:
        return self.hash[key] != math.inf


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)