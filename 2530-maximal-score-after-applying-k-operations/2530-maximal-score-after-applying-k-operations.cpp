class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto n: nums)
            pq.push(n);
        
        long long score = 0;
        while (k-- and !pq.empty()) {
            int cur = pq.top();
            pq.pop();
            score += cur;
            cur = ceil(cur / 3.0);
            if (cur) pq.push(cur);
        }
        return score;
    }
};