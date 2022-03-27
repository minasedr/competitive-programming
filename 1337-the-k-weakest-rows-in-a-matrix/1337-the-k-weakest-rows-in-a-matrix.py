class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        srt = [(n,i) for i,n in enumerate(mat)] 
        srt.sort()
        
        return [srt[i][1] for i in range(k)]
      