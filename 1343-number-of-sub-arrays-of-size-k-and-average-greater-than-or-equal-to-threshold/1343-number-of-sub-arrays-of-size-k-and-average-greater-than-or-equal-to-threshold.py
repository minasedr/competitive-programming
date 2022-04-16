class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        subarray, avg = sum(arr[:k]), k * threshold
        ans = 1 if subarray >= avg else 0
        
        for i in range(len(arr)-k):
            subarray += arr[k+i] - arr[i]
            ans = ans + 1 if subarray >= avg else ans
            
        return ans