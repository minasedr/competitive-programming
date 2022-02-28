class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        center = defaultdict(int)
        
        for edge in edges:
            center[edge[0]] += 1
            center[edge[1]] += 1
            
        highest = max(center.values())
        
        for key, value, in center.items():
            if value == highest:
                return key