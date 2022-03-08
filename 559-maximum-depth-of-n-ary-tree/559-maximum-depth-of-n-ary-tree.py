"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        max_depth = 0
        if not root:
            return 0
        
        if not root.children:
            return 1

        for child in root.children:
            depth = 1 + self.maxDepth(child)
            max_depth = max(max_depth, depth)
                            
        return max_depth