class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> m;
        for (auto x: nums)
            m[x]++;
        int idx = 0;
        for (auto [k, v]: m) {
            for (int i = 0; i < v; i++) {
                nums[idx] = k;
                idx++;
            }
        }
    }
};