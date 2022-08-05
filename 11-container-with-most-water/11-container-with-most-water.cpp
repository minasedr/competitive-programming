class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int beg = 0, end = n - 1, ans = 0;
        while (beg < end) {
            ans = max(ans, (min(height[end], height[beg]) * (end - beg)));
            if (height[beg] < height[end])
                beg++;
            else
                end--;
        }
        return ans;
    }
};