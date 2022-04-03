class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        store, q, n, r = defaultdict(int), deque(), len(nums), 0
        
        for l in range(n):
            while r < n and len(q) < k+1:
                q.append(nums[r])
                if store[nums[r]]: return True
                store[nums[r]] += 1
                r += 1
            q.popleft()
            store[nums[l]] -= 1
            
        return False