class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int start = j + 1, end = n - 1;
                int tar = nums[i] + nums[j];
                while (start < end) {
                    long long cur = nums[start] + nums[end];
                    if (cur + tar < target)
                        start++;
                    else if (cur + tar > target)
                        end--;
                    else
                        st.insert({nums[i], nums[j], nums[start++], nums[end--]});
                }
            }
        }
        for (auto x: st)
            ans.push_back(x);
        return ans;
    }
};