# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        self.tot = 0
        
        def add(root):
            total = 0
            if not root:
                return 0
            if root.left:
                total += root.left.val
            if root.right:
                total += root.right.val
            return total
        
        def dfs(root):
            if not root:
                return
            if root.val % 2 == 0:
                self.tot += add(root.left) + add(root.right)
            dfs(root.left)
            dfs(root.right)
        
        dfs(root)
        return self.tot