const int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long long ans = 0, n = arr.size();
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                int idx = st.top();
                st.pop();
                int start = (st.empty() ? -1 : st.top());
                (ans += (idx - start) * (i - idx) * arr[idx]) %= MOD;
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            int start = (st.empty() ? -1 : st.top());
            (ans += (n - idx) * (idx - start) * arr[idx]) %= MOD;
        }
        return ans;
    }
};