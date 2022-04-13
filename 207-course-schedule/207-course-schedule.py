class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDegrees, outgoing = [0] * numCourses, defaultdict(set)
        
        for course, pre in prerequisites:
            outgoing[pre].add(course)
            inDegrees[course] += 1

        q, count = deque(), 0
        for i in range(numCourses):
            if inDegrees[i] == 0:
                q.append(i)
        
        while q:
            course = q.popleft()
            count += 1
            for neighbor in outgoing[course]:
                inDegrees[neighbor] -= 1
                if inDegrees[neighbor] == 0:
                    q.append(neighbor)
                    
        return count == numCourses