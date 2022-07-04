class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>visited {{0, 1}};
      
        int ans = 0, prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            ans += visited[prefix - k];
            visited[prefix]++;
        }
        return ans;
    }
};