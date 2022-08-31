class Solution {
public:
    bool check(string str1, string str2) {
        unordered_map<char, int> vis;
        for(auto str: str1)
            vis[str]++;
        
        for (auto str: str2) {
            if (vis[str] == 0)
                return false;
            vis[str]--;
        }
        for (auto [k ,v] : vis)
            if (v > 0) return false;
        return true;
    }
    bool reorderedPowerOf2(int n) {
        int cur = 1;
        while (cur <= 1e9) {
            if (check(to_string(cur), to_string(n))) // checks if n is permutation of n
                return true;
            cur *= 2;
        }
        return false;
    }
};