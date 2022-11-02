class Solution {
public:
    int findComplement(int num) {
        unsigned ans = 0;
        int n = log2(num);
        for (int i = 0; i <= n; i++)
            if (not (num & (1 << i)))
                ans += (1 << i);
        
        return ans;
    }
};