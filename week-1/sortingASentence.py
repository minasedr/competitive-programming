class Solution:
    def sortSentence(self, s: str) -> str:
        sent = s.split()
        ordered = ""
        for i in range(1,len(sent)+1):
            for j in range(0,len(sent)):
                if int(sent[j][-1]) == i:
                    ordered += sent[j][:-1] + " "
                    break
        
        return ordered.strip()
