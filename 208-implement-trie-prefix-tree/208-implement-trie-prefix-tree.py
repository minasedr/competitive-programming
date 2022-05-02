class TrieNode:
    def __init__(self, char=""):
        self.char = char
        self.isEnd = False
        self.children = {}
        
class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        current = self.root
        for char in word:
            if char in current.children:
                current = current.children[char]
            else:
                newNode = TrieNode(char)
                current.children[char] = newNode
                current = newNode
        current.isEnd = True

    def search(self, word: str, isPrefix=False) -> bool:
        current = self.root
        for char in word:
            if char not in current.children:
                return False
            current = current.children[char]
        return current.isEnd or isPrefix

    def startsWith(self, prefix: str) -> bool:
        return self.search(prefix, True)


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)