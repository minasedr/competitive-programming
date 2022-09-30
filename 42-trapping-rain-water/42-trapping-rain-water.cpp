class Solution {
public:
    int trap(vector<int>& height) {
        // height = [0,1,0,2,1,0,1,3,2,1,2,1]
        // [3,2, 1]
        // 1 + 1 + 3 + 1
        stack<int>st;
        int n = height.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                int cur = height[st.top()];
                st.pop();
                if (st.empty()) break;
                int high = min(height[i], height[st.top()]) - cur;
                ans += high * (i - st.top() - 1);
            }
            st.push(i);
        }
        return ans;
    }
};