class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval);
        int n = intervals.size();
        if (it == intervals.end())
            intervals.push_back(newInterval);
        else {
            int i = it - intervals.begin();
            intervals.insert(intervals.begin() + i, newInterval);
        }
        
        vector<vector<int>> res;
        for (auto i: intervals) {
            if (res.empty() || res[res.size() - 1][1] < i[0])
                res.push_back(i);
            else {
                res[res.size()-1][1] = (res[res.size() - 1][1] > i[1]? res[res.size()-1][1]: i[1]);
            }
        }
        return res;
    }
};