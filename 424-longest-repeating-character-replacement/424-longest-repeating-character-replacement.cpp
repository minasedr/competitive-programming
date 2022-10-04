class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        
        for (int i = 0; i < 26; i++) {
            vector<int> pref(n + 1);
            
            for (int j = 1; j <= n; j++)
                pref[j] = pref[j - 1] + (s[j - 1] != char('A' + i));
 
            int start = 0;
            for (int end = 1; end <= n; end++) {
                while (pref[end] - pref[start] > k)
                    start++;
                ans = max(ans, end - start);
            }
        }
        return ans;
    }
};