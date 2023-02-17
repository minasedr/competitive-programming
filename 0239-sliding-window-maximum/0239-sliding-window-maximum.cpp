class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            while (!Q.empty() and nums[Q.back()] <= nums[i])
                Q.pop_back();
            Q.push_back(i);
            if (Q.front() <= i - k)
                Q.pop_front();
            if (i >= k - 1)
                ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};