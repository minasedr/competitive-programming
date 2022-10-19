class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0;
        vector<int> ans;

        for (int i = 0; i < n; i++)
            if (nums[i] % 2 == 0)
                sum += nums[i];
                
        for (auto q: queries) {
            int idx = q[1];
            int num = nums[idx] + q[0];
            int inc = 0;
            if (nums[idx] % 2 == 0)
                inc = -nums[idx] + (num % 2 ? 0 : num);
            else
                inc = (num % 2 ? 0: num);
            
            sum += inc;
            nums[idx] = num;
            ans.push_back(sum);
        }
        return ans;
    }
};