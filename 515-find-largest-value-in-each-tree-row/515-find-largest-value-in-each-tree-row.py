# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []
        
        q, ans = deque([root]), []
        
        while q:
            lar = -math.inf
            for _ in range(len(q)):
                ver = q.popleft()
                lar = max(lar, ver.val)
                if ver.left: q.append(ver.left)
                if ver.right: q.append(ver.right)
            ans.append(lar)
            
        return ans