class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size(), ans = 0;
        map<char, int> vis;
        for (auto x: s)
            vis[x]++;
        int cnt = 0;
        for (auto [k, v]: vis) {
            if (v % 2 == 0)
                cnt += v;
            else if (v > 1)
                cnt += v - 1;
                
                
        }
        return (n - cnt > 0 ? cnt + 1: cnt);
    }
};