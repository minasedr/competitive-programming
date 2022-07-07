class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int beg = 0, end = 0;
        
        while (end < n) {
            if (nums[beg] != nums[end])
                nums[++beg] = nums[end];
            end++;
        }
        return beg + 1;
    }
};