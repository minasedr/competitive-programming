class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int diff = abs(nums[i] - 0);
            pq.push({-diff, nums[i]});
        }
        return pq.top().second;
    }
};