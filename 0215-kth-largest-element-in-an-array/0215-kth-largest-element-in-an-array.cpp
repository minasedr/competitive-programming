class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        
        for (auto n: nums) {
            pq.push(n);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};