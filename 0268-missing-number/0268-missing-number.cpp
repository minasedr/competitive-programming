class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0, missing = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            missing ^= nums[i];
            total ^= i;
        }
        
        return total ^ missing;
    }
};