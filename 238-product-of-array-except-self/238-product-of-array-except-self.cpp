class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p{1}, res(n);
        for (int i = 0; i < n; i++) {
            p.push_back(p[p.size() - 1] * nums[i]);
        }
        
        int cur = 1;
        for (int i = n- 1; i >= 0; i--) {
            res[i] = p[i] * cur;
            cur *= nums[i];
        }
        return res;
    }
};