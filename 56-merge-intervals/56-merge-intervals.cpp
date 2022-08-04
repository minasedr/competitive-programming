class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (auto i: intervals) {
            if (res.empty() || res[res.size()-1][1] < i[0])
                res.push_back(i);
            else {
                res[res.size()-1][1] = (res[res.size() - 1][1] > i[1]? res[res.size() - 1][1]: i[1]);
            }
        }
        return res;
    }
};