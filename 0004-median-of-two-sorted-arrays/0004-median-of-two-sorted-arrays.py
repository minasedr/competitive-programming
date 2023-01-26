class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        m, n = len(nums1), len(nums2)
        if m > n: nums1, nums2, m, n = nums2, nums1, n, m
        L, R = 0, m
        while L <= R:
            x = (L + R) // 2
            y = (m + n + 1) // 2 - x
            if x < m and nums1[x] < nums2[y - 1]: L = x + 1
            elif x > 0 and nums1[x - 1] > nums2[y]: R = x - 1
            else:
                if x == 0: left = nums2[y - 1]
                elif y == 0: left = nums1[x - 1]
                else: left = max(nums1[x - 1], nums2[y - 1])
                if (m + n) % 2: return left
                if x == m: right = nums2[y]
                elif y == n: right = nums1[x]
                else: right = min(nums1[x], nums2[y])
                return (left + right) / 2
