class Solution {
public:
    int findComplement(int num) {
        unsigned ans = 0;
        
        for (int i = 0; i <= (int)log2(num); i++)
            if (not (num & (1 << i)))
                ans += (1 << i);
        
        return ans;
    }
};