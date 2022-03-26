class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        store, ans = Counter(nums1), []
        
        for n in nums2:
            if n in store:
                ans.append(n)
                store[n] -= 1
                if store[n] == 0: store.pop(n,0)
                    
        return ans