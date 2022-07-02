class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> freq;
        int n = edges.size();
        for (auto edge: edges) {
            int f = edge[0], s = edge[1];
            freq[f]++;
            freq[s]++;
            if (freq[s] >= n)
                return s;
            if (freq[f] >= n)
                return f;
        }
        return 0;
    }
};