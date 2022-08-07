class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto i: intervals) {
            if (res.empty() || res.back()[1] <= i[0])
                res.push_back(i);
            else
                res.back()[1] = (res.back()[1] > i[1]? i[1]: res.back()[1]);
        }
        return intervals.size() - res.size();
    }
};