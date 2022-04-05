# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root: return TreeNode(val)
        
        def insert(root, val):
            if not root.left and val < root.val:
                root.left = TreeNode(val)
            elif not root.right and val > root.val:
                root.right = TreeNode(val)
            if val < root.val:
                return self.insertIntoBST(root.left,val)
            elif val > root.val:
                return self.insertIntoBST(root.right, val)
            
        insert(root, val)
        return root
        
