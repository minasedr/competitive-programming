class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i, j = len(a) - 1, len(b) - 1
        carry, res = 0, ""
        while i >= 0 or j >= 0:
            cur = carry
            if (i >= 0):
                cur += ord(a[i]) - ord('0')
            if (j >= 0):
                cur += ord(b[j]) - ord('0')
            i, j = i - 1, j - 1
            carry = 1 if cur > 1 else 0
            res += str(cur % 2)
        res += str(carry) if carry else ""
        return res[::-1]