class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans, cur;
        if (path.back() != '/') path += '/';
             
        for (int i = 1; i < path.size(); i++) {
            if (path[i] == '/') {
                if (cur.empty() or cur == ".") {}
                else if (cur == "..") {
                    if (!st.empty()) st.pop();
                } else
                    st.push(cur);
                cur = "";
            } else 
                cur += path[i];
        }    
        while (!st.empty()) {
            cur = st.top();
            reverse(cur.begin(), cur.end());
            ans += cur + '/';
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return (ans.empty() ? "/" : ans);
    }
};