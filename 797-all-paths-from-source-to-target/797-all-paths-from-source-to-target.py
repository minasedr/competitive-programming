class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        visited, ans, N = set(), [], len(graph)
        
        def dfs(i, cur):
            if i >= N-1:
                ans.append(cur)
                return
            for n in graph[i]:
                if n not in visited:
                    dfs(n, cur+[n])
                    
        dfs(0, [0])
        return ans