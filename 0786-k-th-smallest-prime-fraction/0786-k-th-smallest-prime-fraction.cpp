class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, array<int, 2>>> pq;
        int n = arr.size();
        
        for (int i = 0; i < n; i++)
            pq.push({-(double)arr[0] / arr[i], {0, i}});
        
        k--;
        while (!pq.empty() && k--) {
            double sum = pq.top().first;
            auto [i, j] = pq.top().second;
            pq.pop();
            
            if (i < j - 1)
                pq.push({-(double)arr[i+1] / arr[j], {i + 1, j}});
        }
        auto [i, j] = pq.top().second;
        return {arr[i], arr[j]};
    }
};