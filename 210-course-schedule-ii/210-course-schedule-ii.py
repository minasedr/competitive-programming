class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        inDegrees = [0] * numCourses
        graph = defaultdict(list)
        
        for course, pre in prerequisites:
            graph[pre].append(course)
            inDegrees[course] += 1
            
        q, result = deque(), []
        
        for i in range(numCourses):
            if inDegrees[i] == 0:
                q.append(i)
        
        while q:
            course = q.popleft()
            result.append(course)
            for neighbor in graph[course]:
                inDegrees[neighbor] -= 1
                if inDegrees[neighbor] == 0:
                    q.append(neighbor)
                    
        return result if len(result) == numCourses else []