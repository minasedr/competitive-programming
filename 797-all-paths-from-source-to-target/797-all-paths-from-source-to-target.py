class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans, N = [], len(graph)
        
        def dfs(i, cur):
            if i >= N-1:
                ans.append(cur)
                return
            for n in graph[i]:
                dfs(n, cur+[n])
                    
        dfs(0, [0])
        return ans