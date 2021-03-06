"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def __init__(self):
        self.ans = []

    def preorder(self, root: 'Node') -> List[int]:
        if not root: return
        self.ans.append(root.val)

        for ch in root.children:
            self.preorder(ch)
        
        return self.ans