class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        l, r, p = m-1, n-1, m+n-1
                
        while l > -1 and r > -1:
            if nums1[l] > nums2[r]:
                nums1[p], l = nums1[l], l-1
            else:
                nums1[p], r = nums2[r], r-1
            p -= 1
            
        while l > -1:
            nums1[p], l, p = nums1[l], l-1, p-1
            
        while r > -1:
            nums1[p], r, p = nums2[r], r-1, p-1
