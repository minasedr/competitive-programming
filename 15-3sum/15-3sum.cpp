class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int target = 1e6;
        vector<vector<int>> res;
        for (auto x: nums)
            cout << x << " ";
        cout << "\n";
        for (int i = 0; i < n; i++) {
            if (target == nums[i])
                continue;
            int beg = i + 1, end = n - 1;
            target = nums[i];
            while (beg < end) {
                if (nums[beg] + nums[end] == -target) {
                    res.push_back({nums[beg], target, nums[end]});
                    beg++, end--;
                    while (beg < end && nums[beg] == nums[beg - 1] && nums[end] == nums[end+1])
                        beg++, end --;
                }
                else if (nums[beg] + nums[end] < -target)
                    beg++;
                else end--;
            }
        }
        return res;
    }
};