class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxProd = 1, minProd = 1, ans = INT_MIN;
        
        for (auto n : nums) {
            if (n < 0)
                swap(maxProd, minProd);
            maxProd = max(maxProd * n, n);
            minProd = min(minProd *n , n);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};