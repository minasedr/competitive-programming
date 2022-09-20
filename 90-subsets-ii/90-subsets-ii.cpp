class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<vector<int>> res;
        
        for (int i = 0; i < (1 << n); i++) {
            vector<int> cur;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    cur.push_back(nums[j]);
            }
            st.insert(cur);
        }
        for (auto x: st)
            res.push_back(x);
        
        return res;
    }
};