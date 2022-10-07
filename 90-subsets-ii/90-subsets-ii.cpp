class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        set<vector<int>> vis;
        
        for (int i = 0; i < (1 << n); i++) {
            multiset<int> st;
            for (int j = 0; j < 32; j++) {
                if (i & (1 << j))
                    st.insert(nums[j]);
            }
            vector<int> cur(st.begin(), st.end());
            if (!vis.count(cur))
                res.push_back(cur);
            vis.insert(cur);
        }
        return res;
    }
};