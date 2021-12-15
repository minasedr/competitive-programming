class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        output = []
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] > nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]
        
        for k in range(len(nums)):
            if nums[k] == target:
                output.append(k-1)
        return output
