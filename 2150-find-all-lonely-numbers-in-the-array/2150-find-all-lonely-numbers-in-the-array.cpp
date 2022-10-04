class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        map<int,int> cnt;
        for (auto n: nums)
            cnt[n]++;
        
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (cnt[x] == 1 && !cnt[x - 1] && !cnt[x + 1])
                ans.push_back(x);
        }
        return ans;
    }
};