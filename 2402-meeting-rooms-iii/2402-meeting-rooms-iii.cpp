class Solution {
public:
    using i64 = long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n);
        sort(meetings.begin(), meetings.end());
        multiset<pair<i64, i64>> onuse;
        multiset<i64> free;
        
        for (int i = 0; i < n; i++)
            free.insert(i);
        
        for (auto &m : meetings) {
            while (!onuse.empty() && onuse.begin()->first <= m[0]) {
                free.insert(onuse.begin()->second);
                onuse.erase(onuse.begin());
            }
            
            i64 dur = m[1] - m[0];
            i64 start = free.empty() ? onuse.begin()->first : m[0];
            i64 room = free.empty() ? onuse.begin()->second : *free.begin();
            if (free.empty())
                onuse.erase(onuse.begin());
            else
                free.erase(free.begin());
            cnt[room]++;
            onuse.insert({start + dur, room});

        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};