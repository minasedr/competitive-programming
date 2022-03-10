# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        def bfs(root):
            if not root:
                return []
            visited, ans, queue, count = set(), [], deque(), 0
            
            queue.append(root)
            ans.append([queue[0].val])
            
            while queue:
                n, inner = len(queue), []
                count += 1

                for i in range(n):
                    cur = queue.popleft()
                    if cur.left:
                        queue.append(cur.left)
                        inner.append(cur.left.val)
                    if cur.right:
                        queue.append(cur.right)
                        inner.append(cur.right.val)
                if inner and count % 2 == 0:
                    ans.append(inner)
                elif inner:
                    ans.append(inner[::-1])
                print('ans', ans)
                    
            return ans
        
        return bfs(root)