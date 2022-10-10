class Solution {
public:
    int histogram(vector<int>& heights) {
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1));
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (matrix[i - 1][j - 1] == '1')
                    pref[i][j] = pref[i - 1][j] + 1;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            vector<int>cur(pref[i].begin() + 1, pref[i].end());
            ans = max(ans, histogram(cur));
        }
        return ans;
    }
};