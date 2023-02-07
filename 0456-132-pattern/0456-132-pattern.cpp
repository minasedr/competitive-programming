class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), kth = INT_MIN;
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < kth)
                return true;
            while (!st.empty() and st.top() < nums[i]) {
                kth = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};