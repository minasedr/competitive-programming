# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root, node):
        if root:
            self.dfs(root.left,node)
            self.dfs(root.right, node)
            node.append(root.val)
        else:
            return []
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        nodes = []
        self.dfs(root,nodes)
        return nodes