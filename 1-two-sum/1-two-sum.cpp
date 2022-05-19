class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> store;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (store.count(target-nums[i]) > 0)
                return {store[target-nums[i]], i};
            store[nums[i]] = i;
        }
        return {-1, -1};
    }
};