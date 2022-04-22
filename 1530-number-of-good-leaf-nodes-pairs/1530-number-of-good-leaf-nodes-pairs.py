# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        def dfs(root, dist):
            if not root: return []
            if not root.left and not root.right:
                return [1]
            L = dfs(root.left, dist)
            R = dfs(root.right, dist)
            
            for l in L:
                if l > dist: continue
                for r in R:
                    self.pairs += 1 if l + r <= dist else 0
            return [1+d for d in L+R]
        
        self.pairs = 0
        dfs(root, distance)
        return self.pairs