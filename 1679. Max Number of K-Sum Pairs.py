class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        counter = 0
        st, en = 0, len(nums) - 1
        while st < len(nums) and en > st:
            if nums[st] + nums[en] == k:
                counter += 1
                st += 1
                en -= 1
            else:
                if nums[st] + nums[en] < k:
                    st += 1
                elif nums[st] + nums[en] > k:
                    en -= 1
        return counter
