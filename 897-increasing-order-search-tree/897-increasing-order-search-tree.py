# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def f(node):
            if not node: return
            arr.append(node.val)
            f(node.left)
            f(node.right)
            
        arr = []
        f(root)
        arr.sort()
        ans = TreeNode(arr[0])
        
        def dfs(node, i):
            if i >= len(arr): return
            node.left = None
            node.right = TreeNode(arr[i])
            dfs(node.right, i+1)
            
        dfs(ans, 1)
        return ans