# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        
        def dfs(root, cur, target):
            if not root: return
            if not root.left and not root.right:
                if target == root.val:
                    ans.append(cur+[root.val])
                    return
            dfs(root.left, cur+[root.val], target-root.val)
            dfs(root.right, cur+[root.val], target-root.val)
        ans = []
        dfs(root,[], targetSum)
        return ans