class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> res;
        
        for (int i = 0; i < k; i++)
            ms.insert(nums[i]);
        
        for (int i = k; i < (int) nums.size(); i++) {
            res.push_back(*ms.rbegin());
            ms.erase(ms.find(nums[i - k]));
            ms.insert(nums[i]);
        }
        res.push_back(*ms.rbegin());
        return res;
    }
};