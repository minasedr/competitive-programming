class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        map<int,int> m;
        for (auto x: nums) {
            m[x]++;
            if (m[x] > n)
                return x;
        }
        return -1;
    }
};