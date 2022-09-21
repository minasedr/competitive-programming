class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> vis;
        int ans = 0, n = fruits.size(), type = 0;
        int start = 0;
        
        for (int end = 0; end < n; end++) {
            if (vis[fruits[end]] == 0)
                type++;
            vis[fruits[end]]++;
            while (type > 2) {
                vis[fruits[start]]--;
                if (vis[fruits[start]] == 0)
                    type--;
                start++;
            }
            if (type <= 2)
                ans = max(ans, end - start + 1);
        }
        
        return ans;
    }
};