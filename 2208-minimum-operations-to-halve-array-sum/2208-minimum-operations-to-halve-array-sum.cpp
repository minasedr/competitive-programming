class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        
        priority_queue<double>pq;
        for (auto n: nums)
            pq.push(n);
        
        double cur = sum;
        int k = 0;
        while (!pq.empty() && cur > sum / 2.0) {
            auto num = pq.top();
            pq.pop();
            cur -= num / 2.0;
            pq.push(num / 2.0);
            k++;
        }
        return k;
    }
};