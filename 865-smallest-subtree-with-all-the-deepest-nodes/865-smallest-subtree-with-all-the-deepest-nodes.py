# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        
        def dfs(root, d):
            if not root: return (d, None)
            
            left = dfs(root.left, d+1)
            right = dfs(root.right, d+1)
            
            if left[0] > right[0]:
                return left
            elif left[0] < right[0]:
                return right
            return (left[0], root)
        
        return dfs(root, 0)[1]
            