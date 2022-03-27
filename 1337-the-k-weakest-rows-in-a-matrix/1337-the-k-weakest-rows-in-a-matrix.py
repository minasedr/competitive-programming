class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        srt, ans = [], []
        
        for i, n in enumerate(mat):
            srt.append((n,i))
            
        srt.sort()
        for i in range(k):
            ans.append(srt[i][1])
            
        return ans