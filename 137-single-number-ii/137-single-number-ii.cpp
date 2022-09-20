class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        
        for (int i = 0; i < 32; i++) {
            int bit = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & (1 << i))
                    bit++;
            }
            if (bit % 3)
                ans |= (1 << i);
        }
        return ans;
    }
};