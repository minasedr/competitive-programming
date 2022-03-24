# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []
        
        def bfs(root):
            visited, queue, ans, lar = set(), deque(), [], -math.inf
            visited.add(root)
            queue.append(root)
            while queue:
                n = len(queue)
                for _ in range(n):
                    ver = queue.popleft()
                    lar = max(lar, ver.val)
                    if ver.left:
                        queue.append(ver.left); visited.add(ver.left);
                    if ver.right:
                        queue.append(ver.right); visited.add(ver.right);
                ans.append(lar)
                lar = -math.inf
            return ans
        
        return bfs(root)