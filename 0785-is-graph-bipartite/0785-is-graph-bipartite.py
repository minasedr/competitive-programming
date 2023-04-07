class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        ok = True
        color = [-1] * len(graph)
        def dfs(node, col):
            nonlocal ok
            color[node] = col
            
            for nxt in graph[node]:
                if color[nxt] == -1 and not dfs(nxt, col ^ 1):
                        return False
                elif color[node] == color[nxt]:
                    return False
            return True
        
        for i in range(len(graph)):
            if color[i] == -1 and not dfs(i, 0):
                return False
        return True