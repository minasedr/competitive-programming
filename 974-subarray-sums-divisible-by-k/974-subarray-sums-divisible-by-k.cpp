class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>visited(k, 0);
        int ans = 0, cur = 0;
        visited[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            cur = (cur % k + k) % k;
            ans += visited[cur];
            visited[cur]++;
        }
        return ans;
    }
};