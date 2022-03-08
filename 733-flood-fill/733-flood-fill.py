class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        n, m = len(image), len(image[0])
        start_color = image[sr][sc]
        visited = set()

        def dfs(row, col):
            image[row][col] = newColor
            visited.add((row,col))
            
            for dirs in DIR:
                new_row, new_col = row + dirs[0], col + dirs[1]
                if (new_row, new_col) in visited or not inbound(new_row, new_col) or image[new_row][new_col] != start_color:
                    continue
                dfs(new_row, new_col)
        
        DIR = [[0,1],[1,0],[-1,0],[0,-1]]
        inbound = lambda x, y: 0 <= x < n and 0 <= y < m
            
        dfs(sr, sc)
        
        return image