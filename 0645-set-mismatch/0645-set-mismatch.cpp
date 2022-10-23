class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans, cnt(n + 1);
        
        for (auto n: nums)
            cnt[n]++;
        
        int dupl = -1, missing = -1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 1)
                dupl = i;
            else if (cnt[i] == 0)
                missing = i;
        }
        return {dupl, missing};
    }
};