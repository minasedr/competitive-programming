class Solution:
    def sortSentence(self, s: str) -> str:
        demo = ""
        #s = s.split()
        s = sorted(s,key=lambda x:x.split[-1])
        for i in s:
            demo += i[:-1] + " "
        return demo.rstrip()
