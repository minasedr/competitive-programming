class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>seen{{0,1}};
        int ans = 0, cur = 0;
        
        for (int i = 0; i < n; i++) {
            cur += (nums[i] % 2);
            ans += seen[cur - k];
            seen[cur]++;
        }
        return ans;
    }
};
