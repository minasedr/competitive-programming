class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph, visited = defaultdict(list), set()
        
        for ed in edges:
            x, y = ed[0], ed[1]
            graph[x].append(y)
            graph[y].append(x)
            
        def dfs(src, dest):
            visited.add(src)
            for x in graph[src]:
                if x not in visited:
                    dfs(x, dest)
            return dest in visited
        
        return dfs(source, destination)