# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        vis = {inorder[i] : i for i in range(len(inorder))}
        n = len(preorder)
        
        def construct(preSt, preEnd, inSt, inEnd):
            if (preSt > preEnd or inSt > inEnd):
                return None
            root = TreeNode(preorder[preSt])
            elem = vis[preorder[preSt]];
            root.left = construct(preSt + 1, preSt + elem - inSt, inSt, elem - 1)
            root.right = construct(preSt + elem - inSt + 1, preEnd, elem + 1, inEnd)
            
            return root

        return construct(0, n - 1, 0, n - 1)