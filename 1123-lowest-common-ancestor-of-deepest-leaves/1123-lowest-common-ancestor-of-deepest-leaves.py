# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:     
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        def dfs(root, depth):
            if not root:
                return (depth-1, None)
            
            left = dfs(root.left,depth+1)
            right = dfs(root.right, depth+1)
            
            if left[0] == right[0]:
                return (left[0], root)
            if left[0] > right[0]:
                return left
            else:
                return right
            
        return dfs(root,0)[1]