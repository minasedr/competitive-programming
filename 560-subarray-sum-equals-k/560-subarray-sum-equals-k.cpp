class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, cur = 0;
        map<int, int> m{{0,1}};
        
        for (auto x: nums) {
            cur += x;
            cnt += m[cur - k];
            m[cur]++;
            
        }
        return cnt;
    }
};