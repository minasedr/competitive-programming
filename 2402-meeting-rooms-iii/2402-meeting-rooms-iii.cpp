class Solution {
public:
    using i64 = long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n);
        sort(meetings.begin(), meetings.end());
        multiset<pair<i64, int>> pq;
        
        for (int i = 0; i < n; ++i)
            pq.insert({meetings[0][0], i});
        for (auto &m : meetings) {
            while (pq.begin()->first < m[0]) {
                pq.insert({m[0], pq.begin()->second});
                pq.erase(pq.begin());
            }
            auto [start, room] = *pq.begin();
            pq.erase(pq.begin());
            pq.insert({start + m[1] - m[0], room});
            cnt[room]++;
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};