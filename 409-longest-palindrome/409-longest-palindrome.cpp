class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size(), ans = 0, cnt = 0;
        unordered_map<char, int> vis;
        for (auto x: s)
            vis[x]++;
        
        for (auto [k, v]: vis)
            cnt += (v % 2 == 0 ? v : v - 1);
        
        return (n - cnt > 0 ? cnt + 1: cnt);
    }
};