class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        priority_queue<pair<int, char>> pq;
        for (auto c: s)
            cnt[c]++;
        
        for (auto [k, v]: cnt)
            pq.emplace(v, k);
        
        string ans = "";
        while (!pq.empty()) {
            auto [n, c] = pq.top();
            ans += string(n, c);
            pq.pop();
        }
        return ans;
    }
};