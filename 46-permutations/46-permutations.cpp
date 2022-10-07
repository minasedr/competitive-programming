using i64 = long long;
class Solution {
public:
    i64 fact(int n) {
        i64 cnt = 1;
        for (int i = n; i > 1; i--)
            cnt *= i;
        return cnt;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        for (int i = 0; i < fact(nums.size()); i++) {
            res.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return res;
    }
};