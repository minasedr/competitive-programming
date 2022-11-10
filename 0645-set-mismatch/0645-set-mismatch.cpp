class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        vector<int>cnt(N + 1);
        int miss = 0, sum = 0, m = nums.size();

        for (auto n: nums) {
            if (cnt[n]) {
                miss = n;
                continue;
            }
            cnt[n]++;
            sum += n;
        }
        return {miss, (m + 1) * m / 2 - sum};
    }
};