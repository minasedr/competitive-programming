# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        
        def dfs(root):
            nonlocal max_freq
            if not root: return 0
            left = dfs(root.left)
            right = dfs(root.right)
            tot = left + right + root.val
            store[tot] += 1
            max_freq = max(max_freq, store[tot])
            return tot
        
        store = defaultdict(int)
        max_freq = 0
        dfs(root)
        return [val for val in store if store[val] == max_freq]