class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> vis;
        for (auto x: nums) {
            if (vis[x])
                return x;
            vis[x]++;
        }
        return -1;
    }
};