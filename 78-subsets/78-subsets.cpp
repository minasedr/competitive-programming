class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        for (int i = 0; i < (1 << n); i++) {
            vector<int> cur;
            for (int j = 0; j < 32; j++) {
                if (i & (1 << j))
                    cur.push_back(nums[j]);
            }
            res.push_back(cur);
        }
        return res;
    }
};