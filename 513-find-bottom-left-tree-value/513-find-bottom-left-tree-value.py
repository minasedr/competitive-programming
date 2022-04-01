# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        
        while q:
            leftMost = q[0]
            for i in range(len(q)):
                parent = q.popleft()
                if parent.left:
                    q.append(parent.left)
                if parent.right:
                    q.append(parent.right)
                    
        return leftMost.val