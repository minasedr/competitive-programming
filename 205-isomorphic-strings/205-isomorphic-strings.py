class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_index = [s.index(i) for i in s]
        t_index = [t.index(j) for j in t]
            
        return s_index == t_index