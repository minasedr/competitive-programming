# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        
        def dfs(root, arr):
            if not root: return
            dfs(root.left, arr)
            arr.append(root.val)
            dfs(root.right, arr)
        
        arr1, arr2 = [], []
        
        dfs(root1, arr1)
        dfs(root2, arr2)
        
        l, r, ans = 0, 0, []
        N, M = len(arr1), len(arr2)
        
        while l < N and r < M:
            if arr1[l] < arr2[r]:
                ans.append(arr1[l])
                l += 1
            else:
                ans.append(arr2[r])
                r += 1
        return ans + arr1[l:] + arr2[r:]            