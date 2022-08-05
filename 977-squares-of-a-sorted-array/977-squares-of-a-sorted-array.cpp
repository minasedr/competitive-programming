class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int beg = 0, end = n - 1, idx = n - 1;
        vector<int>v(n);
        while (beg <= end) {
            if (nums[beg] * nums[beg] < nums[end] * nums[end]) {
                v[idx--] = nums[end] * nums[end];
                end--;
            }
            else {
                v[idx--] = nums[beg] * nums[beg];
                beg++;
            }
        }
        return v;
    }
};