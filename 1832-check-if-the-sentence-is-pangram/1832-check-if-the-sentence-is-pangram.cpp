class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> vis(26);
        for (char s: sentence)
            vis[s - 'a']++;
        for (auto x: vis)
            if (x == 0) return false;
        return true;
    }
};