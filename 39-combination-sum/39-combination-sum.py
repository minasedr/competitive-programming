class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans, N = [], len(candidates)
        
        def f(i, cur):
            if i >= N: return 0
            
            cur.append(candidates[i])
          
            if sum(cur) < target:
                f(i, cur)
                
            if sum(cur) == target:
                ans.append(cur[:])
            cur.pop()
            f(i+1, cur)
            
        f(0, [])
        return ans