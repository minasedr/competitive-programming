class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        
        def bfs(x):
            visited, queue, n = set(), deque(), len(arr)
            inbound = lambda x: 0 <= x < n
            queue.append(x)
            visited.add(x)
            while queue:
                graph = []
                cur = queue.popleft()
                if not arr[cur]:
                    return True
                if inbound(cur+arr[cur]):
                    graph.append(cur+arr[cur])
                if inbound(cur-arr[cur]):
                    graph.append(cur-arr[cur])
                    
                for neighbor in graph:
                    if neighbor not in visited:
                        queue.append(neighbor)
                        visited.add(neighbor)
                        
            return False
            
        return bfs(start)    