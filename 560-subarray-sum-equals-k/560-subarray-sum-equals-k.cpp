class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>visited {{0, 1}};

        for (int i = 0; i < n; i++)
            nums[i] += i ? nums[i-1]:0;
      
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += visited[nums[i] - k];
            visited[nums[i]]++;
        }
        return ans;
    }
};