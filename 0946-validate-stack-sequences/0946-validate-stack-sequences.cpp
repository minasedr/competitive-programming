class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;
        bool ok = true;
        
        for (auto cur: pushed) {
            st.push(cur);
            while (!st.empty() and st.top() == popped[idx]) {
                idx++;
                st.pop();
            }
        }
        
        while (!st.empty()) {
            if (st.top() != popped[idx])
                ok = false;
            st.pop();
            idx++;
        }
        
        return ok;
    }
};