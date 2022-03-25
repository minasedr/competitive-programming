class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = [0] * len(nums)
        for i in range(len(nums)):
            self.nums[i] = self.nums[i-1] + nums[i]
            
    def sumRange(self, left: int, right: int) -> int:
        if left > 0:
            return self.nums[right] - self.nums[left-1]
        return self.nums[right]

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)