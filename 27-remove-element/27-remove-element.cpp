class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int beg = 0, end = 0;
        
        while (end < n) {
            if (nums[end] != val)
                nums[beg++] = nums[end];
            end++;
        }
        return beg;
    }
};