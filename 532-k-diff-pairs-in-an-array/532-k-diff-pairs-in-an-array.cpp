class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        sort(nums.begin(), nums.end());
        
        set<int> st;
        set<pair<int,int>> vis;
        for (auto x: nums) {
            if (vis.count({x , x - k}))
                continue;
            if (st.count(x - k)) {
                cnt++;
                vis.emplace(x, x - k);
                vis.emplace(x - k, x);
            }
            st.insert(x);
        }
        return cnt;
    }
};