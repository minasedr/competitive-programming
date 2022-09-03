class Solution {
public:
    set<vector<int>> res;
    vector<int> cur;
    void f(int i, vector<int>& nums) {
        if (!res.count(cur))
            res.insert(cur);
        if (i >= nums.size())
            return;
        for (int j = i; j < nums.size(); j++) {
            cur.push_back(nums[j]);
            f(j + 1, nums);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        f(0, nums);
        vector<vector<int>> ans;
        for (auto x: res)
            ans.push_back(x);
        return ans;
    }
};