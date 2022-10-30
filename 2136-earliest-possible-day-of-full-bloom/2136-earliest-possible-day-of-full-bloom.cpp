class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        int n = plantTime.size();
        
        for (int i = 0; i < n; i++) {
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end(), [](pair<int,int>&a, pair<int,int>&b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        });
        
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            cur += v[i].second;
            ans = max(ans, cur + v[i].first);
        }
        
        return ans;
    }
};