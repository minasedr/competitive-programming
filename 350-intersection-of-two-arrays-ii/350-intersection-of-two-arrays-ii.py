class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        store, ans = defaultdict(int), []
        
        for n in nums1:
            store[n] += 1
            
        for n in nums2:
            if n in store:
                ans.append(n)
                store[n] -= 1
                if store[n] == 0: store.pop(n,0)
                    
        return ans