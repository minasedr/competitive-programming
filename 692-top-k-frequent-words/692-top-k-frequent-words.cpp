class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        vector<string> ans;
        for (auto w: words)
            freq[w]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
        for (auto [k, v]: freq)
            pq.emplace(-v, k);
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};