class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        return int(bin(k-1).count("1") % 2 == 1)