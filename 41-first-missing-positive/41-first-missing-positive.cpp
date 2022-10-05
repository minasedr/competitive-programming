const int N = 1e5;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> cnt(N + 1, 1);
        cnt[0] = 0;
        for (auto n: nums)
            if (n > 0 && n < N + 1) cnt[n] = 0;
        
        for (int i = 1; i <= N; i++)
            if (cnt[i]) return i;
        return N + 1;
    }
};