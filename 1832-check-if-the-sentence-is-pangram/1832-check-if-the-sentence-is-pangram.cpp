class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>st;
        for (auto s: sentence)
            st.insert(s);
        return st.size() == 26;
    }
};