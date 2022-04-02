class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        n, cLen, rLen = (len(mat) * len(mat[0])), len(mat[0]), len(mat)
        ans = [[0]* cLen for _ in range(rLen)]
        
        def answer(r,c, k):
            total = 0
            rm = r-k if r>k else 0
            rM = r+k if r+k < rLen else rLen-1
            cm = c-k if c > k else 0
            cM = c+k if c+k < cLen else cLen-1
            
            for j in range(rm, rM+1):
                for k in range(cm, cM+1):
                    total += mat[j][k]
            return total
        
        for i in range(n):
            r, c = divmod(i,cLen)
            ans[r][c] = answer(r,c, k)
            
        return ans