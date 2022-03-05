# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], tar: int) -> bool:

        if not root:
            return False
        
        if not root.left and not root.right:
            return tar == root.val
           
        return self.hasPathSum(root.left, tar-root.val) or self.hasPathSum(root.right, tar-root.val)