class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, end = 0, n = nums.size();
        while (end < n) {
            if (nums[end])
                nums[start++] = nums[end];
            end++;
        }
        while (start < n)
            nums[start++] = 0;
    }
};