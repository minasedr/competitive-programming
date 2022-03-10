class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m, visited,a,b = len(grid), len(grid[0]), set(),0,0
        indices = [(x,y) for x in range(n) for y in range(m)]
        def bfs():
            queue, minutes = deque(), 0
            
            for (x,y) in indices:
                if (x,y) not in visited and grid[x][y] == 2:
                    queue.append((x,y))
                    visited.add((x,y))
                    
            if not queue:
                for (x,y) in indices:
                    if grid[x][y] == 1:
                        return -1
                return 0
            
            while queue:
                n = len(queue)
                for i in range(n):
                    x,y = queue.popleft()
                    grid[x][y] = 2
                    for dirs in DIR:
                        dx, dy = x + dirs[0], y + dirs[1]
                        if (dx,dy) not in visited and inbound(dx,dy) and grid[dx][dy] == 1:
                            queue.append((dx,dy))
                            visited.add((dx,dy))
                minutes += 1
            
            return minutes - 1
        
        
        DIR = [[1,0],[0,1],[0,-1],[-1,0]]
        inbound = lambda x, y: 0 <= x < n and 0 <= y < m
        minutes = bfs()
        
        for (x,y) in indices:
            if (x,y) not in visited and grid[x][y] == 1:
                return -1
            
        return minutes