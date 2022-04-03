class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        store = {}
        
        for idx, n in enumerate(nums):
            if n in store and idx - store[n] <= k:
                return True
            store[n] = idx
            
        return False