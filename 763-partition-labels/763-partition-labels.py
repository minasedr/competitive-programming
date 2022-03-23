class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        store, ans, l, r = {}, [], 0, 0
        
        for i, k in enumerate(s): 
            store[k] = i
        
        for i, k in enumerate(s):
            r = max(r, store[k])
            if r == i:
                ans.append(r-l+1)
                l = r + 1
        
        return ans