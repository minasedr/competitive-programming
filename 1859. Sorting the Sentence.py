class Solution:
    def sortSentence(self, s: str) -> str:
        demo = ""
        s = s.split()
        for i in sorted(s,key=lambda x:x[-1]):
            demo += i[:-1] + " "
        return demo.rstrip()
