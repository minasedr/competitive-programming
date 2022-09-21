class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp{{0, 1}};
        int odds = 0, cnt = 0;
        
        for (int i = 0; i < n; i++) {
            odds += (nums[i] & 1);
            cnt += mp[odds - k];
            mp[odds]++;
        }
        return cnt;
    }
};
