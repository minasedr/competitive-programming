class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, unordered_set<int>> cand;
        int ans = 0;
        
        for (auto x: nums)
            cnt[x]++;
        
        function<void(int, int)> dfs;
        dfs = [&] (int x, int left) {
            cnt[x]--;
            if (not left) ans++;
            for (int y : cand[x])
                if (cnt[y] > 0)
                    dfs(y, left - 1);
            cnt[x]++;
        };
        
        
        for (auto &i : cnt) {
            for (auto &j : cnt) {
                int x = i.first, y = j.first, s = sqrt(x + y);
                if (s * s == x + y)
                    cand[x].insert(y);
            }
        }
        for (auto e : cnt)
            dfs(e.first, nums.size() - 1);
        return ans;
    }
};