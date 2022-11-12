class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size(), ans = 0;
        stack<int> st;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] >= nums[i])) {
                int mid = st.top();
                st.pop();
                int left = (st.empty() ? -1 : st.top());
                ans -= ((long long)nums[mid] * (mid - left) * (i - mid));
            }
            st.push(i);
        }
        
        st = stack<int>();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] <= nums[i])) {
                int mid = st.top();
                st.pop();
                int left = (st.empty() ? -1 : st.top());
                ans += ((long long)nums[mid] * (mid - left) * (i - mid));
            }
            st.push(i);
        }
        return ans;
    }
};