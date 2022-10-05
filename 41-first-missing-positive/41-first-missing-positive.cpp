class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), start = 0;
        // first missing number must be between [1, n + 1];
        // use cycle sort
        // time complexity would be worst case - O(N)
        // space complexity - O(1)
        while (start < n) {
            if (nums[start] > 0 && nums[start] <= n && nums[start] != nums[nums[start] - 1]) {
                swap(nums[start], nums[nums[start] - 1]);
            } else
                start++;
        }
        
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};