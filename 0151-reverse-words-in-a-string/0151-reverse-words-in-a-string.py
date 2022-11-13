class Solution:
    def reverseWords(self, s: str) -> str:
        arr = list(s.split())
        return ' '.join(arr[::-1])