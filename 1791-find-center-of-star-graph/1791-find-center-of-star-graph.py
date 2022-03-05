class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        firTree = set(edges[0])
        secTree = set(edges[1])
        
        return list(firTree.intersection(secTree))[0]
        