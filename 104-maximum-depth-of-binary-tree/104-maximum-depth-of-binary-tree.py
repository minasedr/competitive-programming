# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        depth = 1
        
        if not root:
            return 0
        
        def bfs(root, depth):
            if not root:
                return 0
            if not root.left and not root.right:
                return depth
            return max(bfs(root.left, depth+1), bfs(root.right,depth+1))
        
        return bfs(root, depth)