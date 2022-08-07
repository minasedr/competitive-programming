class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), cnt = 0, maxlen = 0;
        unordered_map<int, int> m{{0, -1}};
        
        for (int i = 0; i < n; i++) {
            cnt += (nums[i] == 0? -1: 1);
            if (m.count(cnt))
                maxlen = max(maxlen, i - m[cnt]);
            else
                m[cnt] = i;
        }
        return maxlen;
    }
};