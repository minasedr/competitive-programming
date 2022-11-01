class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>pref(n + 1);
        
        for (auto x: shifts) {
            pref[x[0]] += (x[2] == 1 ? 1 : -1);
            pref[x[1] + 1] += (x[2] == 1 ? -1 : 1);
        }
        
        for (int i = 1; i <= n; i++)
            pref[i] += pref[i - 1];
        // a%b + b)%b 
        for (int i = 0; i < n; i++)
            s[i] = char('a' + ((s[i] - 'a' + pref[i]) % 26 + 26) % 26);
        
        return s;
    }
};