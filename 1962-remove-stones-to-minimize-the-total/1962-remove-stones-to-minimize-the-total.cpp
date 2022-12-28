class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        for (auto p: piles) {
            pq.push(p);
            sum += p;
        }
        
        while (k--) {
            int pile = pq.top();
            pq.pop();
            sum -= pile / 2;
            int cur = pile - (pile / 2);
            if (cur)
                pq.push(cur);
        }
        return sum;
    }
};