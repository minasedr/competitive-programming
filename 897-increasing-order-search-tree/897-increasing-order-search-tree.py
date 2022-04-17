# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def f(node):
            nonlocal tree
            if not node: return
            f(node.left)
            tree.right = TreeNode(node.val)
            tree = tree.right
            f(node.right)
            
        ans = tree = TreeNode(-1)
        f(root)
        return ans.right