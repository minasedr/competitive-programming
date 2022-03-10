# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ans = []
        
        def bfs(start):
            queue, visited = deque([start]), set()
            visited.add(start)
            
            while queue:
                total = 0
                n = len(queue)
                for i in range(n):
                    cur = queue.popleft()
                    total += cur.val
                    if cur.left:
                        queue.append(cur.left)
                    if cur.right:
                        queue.append(cur.right)
                ans.append(total/n)                                      
                total = 0
        bfs(root)
        
        return ans