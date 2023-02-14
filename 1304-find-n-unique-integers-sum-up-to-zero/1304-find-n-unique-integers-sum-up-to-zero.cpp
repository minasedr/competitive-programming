class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        
        if (n == 1)
            return {0};
        else if (n & 1) {
            ans[1] = 1;
            for (int i = 2; i < n; i++)
                ans[i] = (i & 1 ? i: -i + 1);
        } else {
            for (int i = 1; i <= n / 2 + 1; i++)
                ans[i - 1] = i;
            for (int i = n / 2 + 1; i <= n; i++)
                ans[i - 1] = -ans[i - n / 2 - 1];
        }
        
        return ans;
    }
};