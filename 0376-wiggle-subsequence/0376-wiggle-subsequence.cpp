class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n + 1, 1), neg(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j])
                    neg[i] = max(neg[i], pos[j] + 1);
                else if (nums[i] > nums[j])
                    pos[i] = max(pos[i], neg[j] + 1);
                else {
                    neg[i] = max(neg[i], neg[i - 1]);
                    pos[i] = max(pos[i], pos[i - 1]);
                }
            }
        }
        return max(pos[n - 1], neg[n - 1]);
    }
};