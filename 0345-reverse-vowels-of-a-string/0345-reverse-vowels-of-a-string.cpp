class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        vector<int> vow;
        for (int i = 0; i < n; i++) {
            int x = char(tolower(s[i]));
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                vow.push_back(i);
        }
        int idx = vow.size() - 1;
        string ans = "";
        for (int i = 0; i < n; i++) {
            int x = char(tolower(s[i]));
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                ans +=  s[vow[idx--]];
            else
                ans += s[i];
        }
        return ans;
    }
};