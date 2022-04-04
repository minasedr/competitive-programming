class Solution:
    def toLowerCase(self, s: str) -> str:
        ans = ""
        for i in s:
            if i.isupper():
                ans += i.lower()
            else: ans += i
        return ans