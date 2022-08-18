class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans = 0, cur = 0, n = arr.size();
        unordered_map<int, int> freq;
        for (auto x: arr)
            freq[x]++;
        priority_queue<int> pq;
        for (auto [k ,v]: freq)
            pq.push(v);
        while (!pq.empty() && cur < n / 2) {
            int u = pq.top();
            ans++;
            cur += u;
            pq.pop();
        }
        return ans;
    }
};