class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size(), prev = 0, ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            cur += (gas[i] - cost[i]);
            if (cur < 0) {
                prev += cur;
                cur = 0;
                ans = i + 1;
            }
        }
        return (cur + prev >= 0 ? ans : -1);
    }
};