# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        
        def dfs(root):
            if not root: return (None, 0)
            left = dfs(root.left)
            right = dfs(root.right)
            L = left[1]+1 if root.val == left[0] else 0
            R = right[1]+1 if root.val == right[0] else 0
            self.max = max(self.max, L, R, L+R)
            return (root.val, max(L,R))
            
        self.max = 0
        dfs(root)
        return self.max