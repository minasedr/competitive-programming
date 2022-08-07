class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = []( vector<int>& a,  vector<int>&b) {
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        
        for (auto i: intervals)
            if (res.empty() || res.back()[1] <= i[0])
                res.push_back(i);

        return intervals.size() - res.size();
    }
};