class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        N = len(isConnected)
        parent = [i for i in range(N)]
        rank, res = [1] * N, N
        
        def find(nd):
            while nd != parent[nd]:
                nd = parent[nd]
            return nd
        
        def union(n1, n2):
            p1, p2 = find(n1), find(n2)
            
            if p1 == p2: return 0
            if rank[p1] < rank[p2]:
                parent[p1] = p2
                rank[p2] += rank[p1]
            else:
                parent[p2] = p1
                rank[p1] += rank[p2]
            return 1
        
        for i in range(N):
            for j in range(N):
                if isConnected[i][j]:
                    res -= union(i,j)
                    
        return res