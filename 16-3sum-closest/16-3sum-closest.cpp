class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
      
        long long ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int beg = i + 1, end = n - 1;
            long long cur = INT_MAX;
            while (beg < end) {
                cur = nums[beg] + nums[end] + nums[i];
                if (cur < target)
                    beg++;
                else if (cur > target)
                    end--;
                else
                    return target;
            }
            if (abs(cur - target) < abs(ans - target))
                ans = cur;
        }
        return ans;
    }
};