class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>vis;
        for (int i = 0; i < nums.size(); i++) {
            if (vis[target - nums[i]] > 0)
                return {vis[target - nums[i]] - 1, i};
            vis[nums[i]] = i + 1;
        }
        return {-1, -1};
    }
};