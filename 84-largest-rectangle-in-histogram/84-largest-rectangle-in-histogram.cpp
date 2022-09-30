class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), maxArea = 0, start = 0;
        stack<pair<int,int>> st;
        
        for (int i = 0; i < n; i++) {
            start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                start = st.top().first;
                maxArea = max(maxArea, st.top().second * (i - start));
                st.pop();
            }
            st.push({start, heights[i]});
        }
        return maxArea;
    }
};