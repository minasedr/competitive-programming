"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        
        def dfs(node, G, vis):
            if not node or node in vis:
                return
            vis.add(node)
            if node not in G:
                G[node] = Node(node.val)
            
            for nbr in node.neighbors:
                if nbr not in G:
                    G[nbr] = Node(nbr.val)
                G[node].neighbors.append(G[nbr])
                dfs(nbr, G, vis)
            return G[node]
        
        return dfs(node, {}, set())