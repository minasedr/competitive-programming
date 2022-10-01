class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mnq, mxq;
        int ans = 0, start = 0, n = nums.size();
        
        for (int end = 0; end < n; end++) {
            while (!mnq.empty() && nums[mnq.back()] >= nums[end])
                mnq.pop_back();
            mnq.push_back(end);
            
            while (!mxq.empty() && nums[mxq.back()] <= nums[end])
                mxq.pop_back();
            mxq.push_back(end);
            
            while (nums[mxq[0]] - nums[mnq[0]] > limit) {
                if (mxq[0] <= start)
                    mxq.pop_front();
                if (mnq[0] <= start)
                    mnq.pop_front();
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};