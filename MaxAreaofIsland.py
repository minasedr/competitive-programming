class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        N, M, ans = len(grid), len(grid[0]), 0
        DIR = [(1,0), (0,1), (-1,0),(0,-1)]
        inbound = lambda x,y: 0 <= x < N and 0 <= y < M
        parent, rank = {}, {}
        
        for i in range(N):
            for j in range(M):
                if grid[i][j] == 1:
                    parent[(i,j)] = (i,j)
                    rank[(i,j)] = 1
                    
        def find(nd):
            if nd == parent[nd]:
                return nd
            parent[nd] = find(parent[nd])
            return parent[nd]
            
        def union(n1, n2):
            p1, p2 = find(n1), find(n2)
            if p1 == p2: return 0
            if rank[p1] < rank[p2]:
                parent[p1] = p2
                rank[p2] += rank[p1]
            else:
                parent[p2] = p1
                rank[p1] += rank[p2]
                
            return max(rank[p1], rank[p2])
        
        for i,j in parent:
            if not ans: ans = 1
            for x,y in DIR:
                dx, dy = i+x, j+y
                if inbound(dx,dy) and grid[dx][dy] == 1:
                    ans = max(ans,
                        union((i,j), (dx,dy))
                    )
        return ans
