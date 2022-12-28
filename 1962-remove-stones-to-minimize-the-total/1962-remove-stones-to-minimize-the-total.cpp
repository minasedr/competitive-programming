class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (auto p: piles)
            pq.push(p);
        
        while (k--) {
            int pile = pq.top();
            pq.pop();
            int cur = pile - (pile / 2);
            if (cur)
                pq.push(cur);
        }
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};