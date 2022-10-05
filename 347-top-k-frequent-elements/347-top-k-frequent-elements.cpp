class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int, int> cnt;
        vector<int> ans;
        
        for (auto n: nums)
            cnt[n]++;
        for (auto [k, v]: cnt)
            pq.emplace(v, k);
        
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};