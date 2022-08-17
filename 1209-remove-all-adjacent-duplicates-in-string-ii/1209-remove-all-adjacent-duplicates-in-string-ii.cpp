class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        string res = "";
        
        for (auto x: s) {
            if (!st.empty() && st.top().first == x) {
                st.top().second++;
                if (st.top().second == k)
                    st.pop();
            }
            else
                st.push({x, 1});
        }
        
        while (!st.empty()) {
            auto it = st.top();
            while (it.second--) {
                res += it.first;
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};