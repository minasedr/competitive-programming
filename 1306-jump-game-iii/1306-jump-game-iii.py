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
                
                
                
                
                
                
                
#             while arr[x]:
#                 visited.add(x)
#                 if inbound(x+arr[x]) and x+arr[x] not in visited:
#                     x += arr[x]
#                 elif inbound(x-arr[x]) and x-arr[x] not in visited:
#                     x -= arr[x]
#                 if x+arr[x] in visited and x-arr[x] in visited:
#                     break
#                 if x+arr[x] in visited and not inbound(x-arr[x]):
#                     break
#                 if x-arr[x] in visited and not inbound(x+arr[x]):
#                     break
#                 if not inbound(x-arr[x]) and not inbound(x+arr[x]):
#                     break

#             return True if not arr[x] else False
#         return bfs(start)