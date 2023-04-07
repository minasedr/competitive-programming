class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        ok = True
        color = [-1] * len(graph)
        def dfs(node, col):
            nonlocal ok
            color[node] = col
            
            for nxt in graph[node]:
                if color[nxt] == -1:
                    dfs(nxt, col ^ 1)
                elif color[node] == color[nxt]:
                    ok = False
        for i in range(len(graph)):
            if color[i] == -1:
                dfs(i, 0)
        
        return ok