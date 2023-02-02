class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> vis;
        for (int n: nums)
            if (n) vis.insert(n);
        
        return vis.size();
    }
};