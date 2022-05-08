class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        stack, rem = [], len(nums) - k
        
        for num in nums:
            while rem > 0 and stack and stack[-1] > num:
                stack.pop()
                rem -= 1
            stack.append(num)
            
        for _ in range(rem):
            stack.pop()
        return stack