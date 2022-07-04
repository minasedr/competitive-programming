class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>front(n+1, 1);
        vector<int>back(n+1, 1);
        vector<int>ans(n);
        
        for (int i = 1; i <= n; i++) 
            front[i] = front[i-1] * nums[i-1];
        
        for (int i = n-1; i >= 0; i--) 
            back[i] = back[i+1] * nums[i];
        
        for (int i = 0; i < n; i++)
            ans[i] = front[i] * back[i+1];
        
        return ans;
    }
};