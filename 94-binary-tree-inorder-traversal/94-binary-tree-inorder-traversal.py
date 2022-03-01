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
            node.append(root.val)
            self.dfs(root.right,node)
        else:
            return []
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        nodes = []
        self.dfs(root,nodes)
        return nodes