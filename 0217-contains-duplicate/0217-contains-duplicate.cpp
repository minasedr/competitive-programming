class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> vis(nums.begin(), nums.end());
        return vis.size() < nums.size();        
    }
};