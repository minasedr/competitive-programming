class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;
        
        for (auto cur: pushed) {
            st.push(cur);
            while (!st.empty() and st.top() == popped[idx]) {
                idx++;
                st.pop();
            }
        }
        
        return idx == popped.size();
    }
};