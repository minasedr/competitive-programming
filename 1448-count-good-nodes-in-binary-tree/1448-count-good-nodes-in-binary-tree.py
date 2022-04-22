# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        def dfs(root, M):
            if not root: return
            if root.val >= M:
                self.res += 1
            M = max(root.val, M)
            
            dfs(root.left, M)
            dfs(root.right, M)
        self.res = 0
        dfs(root, root.val)
        return self.res