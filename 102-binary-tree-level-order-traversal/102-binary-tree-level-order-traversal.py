# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return
        
        def height(root):
            if not root: return 0
            return max(height(root.left), height(root.right))+1
        
        ans = [[] for _ in range(height(root))]
        
        def traverse(root, level):
            if not root: return
            ans[level].append(root.val)
            traverse(root.left, level + 1)
            traverse(root.right, level+1)
            
        traverse(root,0)
        return ans

#         q, ans = deque([root]), []
#         while q:
#             d = [0] * len(q)
#             for i in range(len(q)):
#                 node = q.popleft()
#                 d[i] = node.val
#                 if node.left: q.append(node.left)
#                 if node.right: q.append(node.right)
#             ans.append(d)
#         return ans