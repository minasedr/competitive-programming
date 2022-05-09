class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res, N = [], len(candidates)
        
        def btrack(i, tot, cur):
            if i >= N or tot > target:
                return 0
            if tot == target:
                res.append(cur)
                return
            for j in range(i, N):
                x = candidates[j]
                btrack(j, tot+x, cur+[x])
            return res
        
        return btrack(0, 0, [])