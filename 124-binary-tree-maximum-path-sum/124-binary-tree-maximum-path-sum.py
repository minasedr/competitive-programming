# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        
        def dfs(root):
            if not root: return 0
            left = dfs(root.left)
            right = dfs(root.right)
            self.max = max(self.max, left+root.val, right+root.val, left+right+root.val, root.val)

            return max(root.val, left+root.val, right+root.val)
        
        self.max = -inf
        dfs(root)
        return self.max
