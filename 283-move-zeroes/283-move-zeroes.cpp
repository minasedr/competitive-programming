class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int beg = 0, end = 0;
        
        while (beg < n || end < n) {
            if (end == n) {
                nums[beg++] = 0;
                continue;
            }
            if (nums[end] != 0)
                nums[beg++] = nums[end];
            end++;
        }
    }
};