class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l, r , arr = 0,0, []
        while l < len(nums1) and r < len(nums2):
            if nums1[l] < nums2[r]:
                arr.append(nums1[l])
                l += 1
            else:
                arr.append(nums2[r])
                r += 1
        if l < len(nums1):
            arr.extend(nums1[l:])
        if r < len(nums2):
            arr.extend(nums2[r:])
   
        n = len(arr)
        
        if n % 2 == 0:
            return (arr[n//2] + arr[n//2-1])/2
        else:
            return arr[n//2]