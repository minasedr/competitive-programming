class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_index, t_index = [], []
        for i in s:
            s_index.append(s.index(i))
        for j in t:
            t_index.append(t.index(j))
            
        return s_index == t_index
