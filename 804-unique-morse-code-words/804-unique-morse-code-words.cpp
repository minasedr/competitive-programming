class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mapping = {".-","-...","-.-.","-..",".","..-.",
            "--.","....","..",".---","-.-",".-..", "--","-.","---",
            ".--.","--.-",".-.", "...","-","..-","...-",".--","-..-",
            "-.--","--.."};
        
        set<string> st;
        int ans = 0;
        for (auto word: words) {
            string cur;
            for (auto w: word)
                cur += mapping[w -'a'];
            if (!st.count(cur)) {
                st.insert(cur);
                ans++;
            }
        }
        return ans;
    }
};