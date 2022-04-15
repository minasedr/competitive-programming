class Solution:
    def check(self, nums: List[int]) -> bool:
        A = sorted(nums)
        B = nums
        fir = []
        for x in range(len(B)):
            if B[x] == A[0]:
                fir.append(x)
                
        for i in fir:
            isRotated = True
            for j in range(len(B)):
                if A[j] != B[(j+i)%len(A)]:
                    isRotated = False
                    break
            if isRotated: return True
        return False