class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        N = len(arr)
        dp = [[0,0] for _ in range(N)]
        
        for i in range(N):
            x = N-i-1
            if i > 0 and arr[i] > arr[i-1]:
                dp[i][0] = 1 + dp[i-1][0]
            if x > 0 and arr[x] < arr[x-1]:
                dp[x-1][1] = 1 + dp[x][1]
                
        res = [sum(pt) for pt in dp if pt[0] and pt[1]]
        return max(res)+1 if res else 0