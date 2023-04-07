class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for edge in prerequisites:
            adj[edge[1]].append(edge[0])
        
        visited = [0] * numCourses
        def dfs(node):
            visited[node] = 1
            for nxt in adj[node]:
                if visited[nxt] == 0:
                    if not dfs(nxt):
                        return False
                elif visited[nxt] == 1:
                    return False
            visited[node] = 2
            return True
        
        for i in range(numCourses):
            if visited[i] == 0 and not dfs(i):
                return False
        return True