class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        graph, N = defaultdict(list), len(rooms)
        
        for idx, room in enumerate(rooms):
            graph[idx].extend(room)

        def dfs(i):
            if i >= N: return
            visited.add(i)
            for j in graph[i]:
                if j not in visited: dfs(j)
        
        visited = set()
        dfs(0)
        return len(visited) == N