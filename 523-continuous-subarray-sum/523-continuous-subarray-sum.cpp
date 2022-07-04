class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int>visited{{0,-1}};
        int cur_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            cur_sum = (cur_sum + nums[i]) % k;
            if (!visited.count(cur_sum))
                visited[cur_sum] = i;
            else if (i - visited[cur_sum] > 1)
                return true;
        }
        return false;
    }
};